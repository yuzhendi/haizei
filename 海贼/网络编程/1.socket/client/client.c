/*************************************************************************
	> File Name: client.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月22日 星期四 11时16分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s ip port", argv[0]);
    }
    
    int sockfd, port;
    port = atoi(argv[2]);
    struct sockaddr_in server;
    
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }
    printf("berore send...\n"); 
    if (send(sockfd, "yuzhendi", sizeof("yuzhendi"), 0) < 0 ){
        perror("send");
        exit(1);
    }
    printf("after send...\n");
    close(sockfd);

    return 0;
}

