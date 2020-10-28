/*************************************************************************
	> File Name: client.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月28日 星期三 18时45分26秒
 ************************************************************************/

#include "../common/head.h"
#include "../common/tcp_client.h"

int main(int argc, char **argv) {
    int sockfd;
    if (argc != 4) {
        fprintf(stderr, "格式： ./a.out ip port timeout\n", argv[0]);
        return 1;
    }
    
    if ((sockfd = socket_connect_timeout(argv[1], atoi(argv[2]), atoi(argv[3]))) < 0) {
        perror("socket_connect_timeout");
        return 2;
    }
    printf("请输入要发送的信息\n");
    while(1) {
        char msg[512] = {0};
        scanf("%s", msg);
        if (send(sockfd, msg, sizeof(msg), 0) < 0) {
            perror("send");
            return 3;
        }
    }
    
    return 0;
}
