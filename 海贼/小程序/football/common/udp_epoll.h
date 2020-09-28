/*************************************************************************
	> File Name: udp_epoll.h
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月05日 星期五 21时05分26秒
 ************************************************************************/

#ifndef _UDP_EPOLL_H
#define _UDP_EPOLL_H
#include "./datatype.h"
void add_event(int epoll_fd, int fd, int events);
void del_event(int epoll_fd, int fd, int events);
//void udp_connect(int epoll_fd, int fd, struct sockaddr_in *server);
int udp_accept(int epoll_fd, int fd, struct User *user);
void add_to_sub_reactor(struct User *user);
#endif
