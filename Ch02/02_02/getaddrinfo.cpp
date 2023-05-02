//
// Created by amrit on 16/4/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

//struct addrinfo {
//    int ai_flags;           // input flags
//    int ai_family;          //socket protocol family
//    int ai_socktype;        // socket type
//    int ai_protocol;        // protocol for socket
//    socklen_t ai_addrlen;   // socket addr length
//    struct *ai_canonname;   // socket address
//    struct  addrinfo *ai_next; // next item in the list
//};

int main(){

    const char *host = "google.com";
    const char *port = "80";
    int r;
    struct addrinfo hint, *resource;

    printf("Configuring host..");
    memset(&hint, 0, sizeof (struct addrinfo));
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;

    r = getaddrinfo(host, port, &hint, &resource);
    if (r != 0){
        perror("Failed");
        exit(1);
    }
    puts("Done");

    freeaddrinfo(resource);

    return 0;
}