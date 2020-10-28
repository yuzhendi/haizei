/*************************************************************************
	> File Name: tcp_server.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月28日 星期三 18时16分06秒
 ************************************************************************/

#include "head.h"
int socket_create(int port) {
    int server_listen;
    if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    struct linger m_linger; // 设置延时时间
    m_linger.l_onoff = 1;
    m_linger.l_linger = 0; // 延时关闭，直接关闭
    if (setsockopt(server_listen, SOL_SOCKET, SO_LINGER, &m_linger, (socklen_t)sizeof(m_linger)) < 0) {
        return -1;
    }
    int flag = 1;// 1 表示地址重用
    if (setsockopt(server_listen, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int)) < 0) { // 设置地址重用
        return -1;
    }


    if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return -1;
    }

    if (listen(server_listen, 20) < 0){
        return -1;
    }
    return server_listen;
}

