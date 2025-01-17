#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <poll.h>
#include <unistd.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(9999);
    address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(sockfd, (const struct sockaddr *)&address, sizeof(address));
    if (connection_status == -1) 
        printf("There was an error making a connection to the remote socket \n\n");

    char buffer[256] = { 0 };
    recv(sockfd, buffer, 255, 0);
    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}