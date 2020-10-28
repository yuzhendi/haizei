/*************************************************************************
	> File Name: tcp_client.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月28日 星期三 18时22分23秒
 ************************************************************************/

#include "head.h"
#include "common.h"

int socket_connect(char *host, int port) {
    // 客户端进行套结字的创建和连接
    // 返回 sockfd

    int sockfd;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    printf("socket");

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return -1;
    }
    return sockfd;

}

int socket_connect_timeout(char *host, int port, long timeout) {
    int sockfd;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    make_nonblock(sockfd); // 设置缓冲区为非阻塞，没有响应立即返回

    struct timeval tv; // 设置超时时间
    tv.tv_sec = 0;
    tv.tv_usec = timeout;
    
    fd_set wfds;
    FD_ZERO(&wfds);
    FD_SET(sockfd, &wfds);

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        // 连接失败
        int retval, error = -1;
        int len = sizeof(int);
        retval = select(sockfd + 1, NULL, &wfds, NULL, &tv); // select控制时间
        if (retval < 0) {
            close(sockfd);
            return - 1; // 出错
        } else if (retval) {
            if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, (socklen_t *)&len) < 0) {
                close(sockfd);
                return -1;
            }
            if(error) {
                close(sockfd);
                return -1;
            }
        } else {
            printf("connect time out!\n");
            close(sockfd);
            return -1;
        }
    }
    make_block(sockfd); // 再恢复为阻塞
    return sockfd;
}
