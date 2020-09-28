/*************************************************************************
	> File Name: server.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月04日 星期四 18时10分22秒
 ************************************************************************/

#include "../common/head.h"
#include "../common/color.h"
#include "../common/common.h"
#include "../common/udp_server.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port!\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int sockfd;
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    char msg[512] = {0};
    if (sockfd = socket_create_udp(port) < 0) {
        perror("socket_create_udp");
        exit(1);
    }
    recvfrom(sockfd, msg, sizeof(msg), 0, (struct sockaddr *)&client, &len);

    printf("D: recv : %s \n", msg);

    if (connect(sockfd, (struct sockaddr *)&client, len) < 0) {
        perror("connect");      //发一个数据包，没有三次握手，sockfd只服务一个用户
        exit(1);
    }
    
    send(sockfd, "Hello!", sizeof("Hello!"), 0);

    //recvfrom
    return 0;
}
