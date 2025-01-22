#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EVENTS 10
#define PORT 8080
#define BUFFER_SIZE 1024

// Function to set a socket to non-blocking mode
int set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl F_GETFL");
        return -1;
    }
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl F_SETFL");
        return -1;
    }
    return 0;
}

int main() {
    int server_fd, epoll_fd;
    struct epoll_event ev, events[MAX_EVENTS];
    struct sockaddr_in server_addr, client_addr;

    // Create a server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server socket to non-blocking mode
    if (set_nonblocking(server_fd) == -1) {
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections on any interface
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, SOMAXCONN) == -1) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Create an epoll instance
    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1 failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Add the server socket to the epoll instance
    ev.events = EPOLLIN; // Monitor for incoming connections
    ev.data.fd = server_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &ev) == -1) {
        perror("epoll_ctl failed");
        close(server_fd);
        close(epoll_fd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Wait for events
        int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait failed");
            break;
        }

        // Handle each event
        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == server_fd) {
                // New client connection
                socklen_t addr_len = sizeof(client_addr);
                int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
                if (client_fd == -1) {
                    perror("accept failed");
                    continue;
                }

                printf("New connection from %s:%d\n",
                       inet_ntoa(client_addr.sin_addr), // Converts IP to human-readable format
                        ntohs(client_addr.sin_port));    // Converts port to host byte order

                // Set the client socket to non-blocking mode
                if (set_nonblocking(client_fd) == -1) {
                    close(client_fd);
                    continue;
                }

                // Add the client socket to the epoll instance
                ev.events = EPOLLIN | EPOLLET; // Monitor for incoming data (edge-triggered)
                ev.data.fd = client_fd;
                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &ev) == -1) {
                    perror("epoll_ctl failed for client_fd");
                    close(client_fd);
                    continue;
                }
            } else {
                // Data available on a client socket
                int client_fd = events[i].data.fd;
                char buffer[BUFFER_SIZE];

                // Read data from the client
                int bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
                if (bytes_read > 0) {
                    buffer[bytes_read] = '\0'; // Null-terminate the buffer
                    printf("Received from client: %s\n", buffer);

                    // Echo the data back to the client
                    if (write(client_fd, buffer, bytes_read) == -1) {
                        perror("Write failed");
                    }
                } else if (bytes_read == 0) {
                    // Client disconnected
                    printf("Client disconnected\n");
                    close(client_fd);
                } else if (bytes_read == -1 && errno != EAGAIN) {
                    // Read error
                    perror("Read failed");
                    close(client_fd);
                }
            }
        }
    }

    // Clean up
    close(server_fd);
    close(epoll_fd);
    return 0;
}
