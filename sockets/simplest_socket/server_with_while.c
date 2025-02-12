#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <poll.h>
#include <unistd.h>
#include<fcntl.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    fcntl(sockfd, F_SETFL, O_NONBLOCK); //entendo que estou dizendo que sockfd não é capaz de bloquear o accept, caso contrário, o accept fica esperando
    //que tenha algo em sockfd (uma conexão) e bloqueia o processo

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(9999);
    address.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (const struct sockaddr *)&address, sizeof(address));

    listen(sockfd, 10);

    printf("Pre Waiting ...\n");
    while(1) {
        int clientfd = accept(sockfd, 0, 0);

        printf("Waiting ...\n");

        char buffer[256] = "Eu vim do servidor";

        int a = send(clientfd, buffer, 255, 0);
        if (a != -1) {
            printf("FIM\n");
            close(sockfd);
            return 0;
        }
    }
    return 0;
}