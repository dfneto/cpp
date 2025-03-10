// server.c - a micro-server that accepts a client connection, waits for a message, and replies
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 9999  // our server's port
#define BACKLOG 10  // max number of connection requests in queue

int main(void)
{
    printf("---- SERVER ----\n\n");
    struct sockaddr_in sa;
    int socket_fd;
    int client_fd;
    int status;
    struct sockaddr_storage client_addr;
    socklen_t addr_size;
    char buffer[BUFSIZ];
    int bytes_read;

    // Prepare the address and port for the server socket
    memset(&sa, 0, sizeof sa);
    sa.sin_family = AF_INET; // IPv4
    sa.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // 127.0.0.1, localhost
    sa.sin_port = htons(PORT);

    // Create socket, bind it and listen with it
    socket_fd = socket(sa.sin_family, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        fprintf(stderr, "socket fd error: %s\n", strerror(errno));
        return (1);
    }
    printf("Created server socket fd: %d\n", socket_fd);

    status = bind(socket_fd, (struct sockaddr *)&sa, sizeof sa);
    if (status != 0) {
        fprintf(stderr, "bind error: %s\n", strerror(errno));
        return (2);
    }
    printf("Bound socket to localhost port %d\n", PORT);

    printf("Listening on port %d\n", PORT);
    status = listen(socket_fd, BACKLOG);
    if (status != 0) {
        fprintf(stderr, "listen error: %s\n", strerror(errno));
        return (3);
    }

    // Accept incoming connection
    addr_size = sizeof client_addr;
    client_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &addr_size);
    if (client_fd == -1) {
        fprintf(stderr, "client fd error: %s\n", strerror(errno));
        return (4);
    }
    printf("Accepted new connection on client socket fd: %d\n", client_fd);

    // Receive message from client socket
    bytes_read = 1;
    while (bytes_read >= 0) {
        printf("Reading client socket %d\n", client_fd);
        bytes_read = recv(client_fd, buffer, BUFSIZ, 0);
        if (bytes_read == 0) {
            printf("Client socket %d: closed connection.\n", client_fd);
            break ;
        }
        else if (bytes_read == -1) {
            fprintf(stderr, "recv error: %s\n", strerror(errno));
            break ;
        }
        else {
            // We got a message, print it
            // and send a message back to client
            char *msg = "Got your message.";
            int msg_len = strlen(msg);
            int bytes_sent;

            buffer[bytes_read] = '\0';
            printf("Message received from client socket %d: \"%s\"\n", client_fd, buffer);

            bytes_sent = send(client_fd, msg, msg_len, 0);
            if (bytes_sent == -1) {
                fprintf(stderr, "send error: %s\n", strerror(errno));
            }
            else if (bytes_sent == msg_len) {
                printf("Sent full message to client socket %d: \"%s\"\n", client_fd, msg);
            }
            else {
                printf("Sent partial message to client socket %d: %d bytes sent.\n", client_fd, bytes_sent);
            }
        }
    }

    printf("Closing client socket\n");
    close(client_fd);
    printf("Closing server socket\n");
    close(socket_fd);

    return (0);
}