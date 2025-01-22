#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/event.h>
#include <sys/socket.h>
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
    int server_fd, kq;
    struct sockaddr_in server_addr, client_addr;
    struct kevent change_event, event_list[MAX_EVENTS];

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

    // Create a kqueue instance
    kq = kqueue();
    if (kq == -1) {
        perror("kqueue failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Add the server socket to the kqueue instance
    EV_SET(&change_event, server_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
    if (kevent(kq, &change_event, 1, NULL, 0, NULL) == -1) {
        perror("kevent failed to add server_fd");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Wait for events
        int event_count = kevent(kq, NULL, 0, event_list, MAX_EVENTS, NULL);
        if (event_count == -1) {
            perror("kevent failed");
            break;
        }

        // Handle each event
        for (int i = 0; i < event_count; i++) {
            if ((int) event_list[i].ident == server_fd) {
                // New client connection
                socklen_t addr_len = sizeof(client_addr);
                int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
                if (client_fd == -1) {
                    perror("accept failed");
                    continue;
                }

                printf("New connection from %s:%d\n",
                       inet_ntoa(client_addr.sin_addr),
                       ntohs(client_addr.sin_port));

                // Set the client socket to non-blocking mode
                if (set_nonblocking(client_fd) == -1) {
                    close(client_fd);
                    continue;
                }

                // Add the client socket to the kqueue instance
                EV_SET(&change_event, client_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
                if (kevent(kq, &change_event, 1, NULL, 0, NULL) == -1) {
                    perror("kevent failed to add client_fd");
                    close(client_fd);
                    continue;
                }
            } else {
                // Data available on a client socket
                int client_fd = event_list[i].ident;
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
    close(kq);
    return 0;
}
