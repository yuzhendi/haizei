/*************************************************************************
	> File Name: server.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月22日 星期四 10时57分38秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
void Stderr(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port\n", argv[0]);
        exit(1);
    }
}


int main(int argc, char **argv) {
    Stderr(argc, argv);
    int port, server_listen; 
    port = atoi(argv[1]); // 获取端口

    if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) { // 创建套结字
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server;// 初始化结构体存储数据
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_listen, 20) < 0) {
        perror("listen");
        exit(1);
    }
    
    while(1) {
        int sockfd;
        if ((sockfd = accept(server_listen, NULL, NULL)) < 0) { // NULL 默认状态
            perror("accept");
            close(sockfd);
            continue;
        }
        char name[20] = {0};
        if (recv(sockfd, name, sizeof(name), 0) <= 0) {
            close(sockfd);
            continue;
        }
        printf("%s\n", name);
    }

    return 0;
}
