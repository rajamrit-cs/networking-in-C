#include "stdio.h"
#include "stdlib.h"
#include "sys/socket.h"
#include "unistd.h"
#include "string.h"
#include "netdb.h"


int main(){

    int sockfd, r;
    struct addrinfo hint, *server;

    memset(&hint, 0, sizeof (struct addrinfo));
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;

    r = getaddrinfo(0, "8080", &hint, &server);
//    Success if r is 0
    if( r!= 0)
    {
        perror("failed");
        exit(1);
    }
    puts("get addr info done...");

    printf("Assigning a socket...\n");

    sockfd = socket(
            server->ai_family,
            server->ai_socktype,
            server->ai_protocol
            );
    if (sockfd == -1){
        perror("Could not create socket");
        exit(0);
    }
    puts("Socket created...");

    close(sockfd);
    puts("Socket closed...");
    return 0;
}