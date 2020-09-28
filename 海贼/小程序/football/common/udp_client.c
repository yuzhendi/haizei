/*************************************************************************
	> File Name: udp_clien.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月07日 星期日 10时49分48秒
 ************************************************************************/

#include "head.h"
int sock_udp(){
    int sockfd;

    if((sockfd = socket(AF_INET, SOCK_DGRAM,0)) < 0) {
        perror("socket");
        return -1;
    }
    printf("socket create.\n");
    return sockfd;
} 

