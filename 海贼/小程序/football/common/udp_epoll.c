/*************************************************************************
	> File Name: udp_eopll.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月04日 星期四 19时07分10秒
 ************************************************************************/
#include "./color.h"
#include "./common.h"
#include "./udp_client.h"
#include "./udp_server.h"
#include "./head.h"
#define MAX 50
extern int port;
extern struct User *bteam;
extern struct User *rteam;
extern int repollfd, bepollfd;

void  add_event(int epollfd, int fd, int events){

    struct epoll_event ev;
    ev.events = events;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
    DBG(YELLOW"EPOLL"NONE" : After Epoll Add.\n");
}
void  add_event_ptr(int epollfd, int fd, int events, struct User *user){
    struct epoll_event ev;  // ev 是一个联合体
    ev.events = events;
    ev.data.ptr = (void *)user;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
    DBG(L_GREEN"Sub Thread"NONE" : After Epoll Add + %s.\n", user->name);
}


void del_event(int epollfd, int fd, int events) {
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = events;
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, &ev);
}

int udp_connect(int epollfd, struct sockaddr_in *serveraddr) {
    int sockfd;
    if ((sockfd = socket_create_udp(port)) < 0) {
        perror("socket_udp");
        return -1;
    }
    DBG(GREEN"INFO"NONE" : Before connect.\n");
    if (connect(sockfd, (struct sockaddr *)serveraddr, sizeof(struct sockaddr)) < 0) {
        perror("connect");
        return -1;
    }
    DBG(GREEN"INFO"NONE" : After connect.\n");
    int ret = send(sockfd, "Login!", sizeof("Login!"), 0);
    DBG(RED"RET = %d\n"NONE, ret);
    //add_event(epollfd, sockfd, EPOLLIN);
    return sockfd;
}

int udp_accept(int epollfd, int fd, struct User *user) {
    struct sockaddr_in client;
    int new_fd, ret;
    struct LogRequest request;
    struct LogResponse response;

    bzero(&request, sizeof(request));
    bzero(&response, sizeof(response));

    socklen_t len  = sizeof(struct sockaddr_in);
    ret = recvfrom(fd, (void *)&request, sizeof(request), 0, (struct sockaddr *)&client, &len);
    if (ret != sizeof(request)) {
        response.type = 1;
        strcpy(response.msg, "Login failed.");
        sendto(fd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&client, len);
        return -1;
    }
    response.type = 0;
    strcpy(response.msg, "Login success. Enjoy yourself.");
    sendto(fd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&client, len);

    //*t = request.team;

    if (request.team)
        DBG(GREEN"INFO"NONE" : "BLUE" %s on %s:%d login! (%s)\n"NONE, request.name, inet_ntoa(client.sin_addr), ntohs(client.sin_port), request.msg);
    else
        DBG(GREEN"INFO"NONE" : "RED" %s on %s:%d login! (%s)\n"NONE, request.name, inet_ntoa(client.sin_addr), ntohs(client.sin_port), request.msg);

    strcpy(user->name, request.name);
    user->team = request.team;
    new_fd = udp_connect(epollfd, &client);
    user->fd = new_fd;
    return new_fd;
}

int find_sub(struct User *user) {
    for (int i= 0; i < MAX; i++) {
        if (!rteam[i].online) return i;
    }
    return -1;
} 

void add_to_sub_reactor(struct User *user) {
    struct User *team = (user->team ? bteam : rteam);
    DBG(YELLOW"Main Thread : "NONE"Add to sub_reactor");
    int sub = find_sub(team);
    team[sub] = *user; // 结构体复制
    team[sub].online = 1;
    team[sub].flag = 10;
    DBG(L_RED"sub = %d, name = %s\n"NONE, sub, team[sub].name);
    if (user->team) {
        add_event_ptr(bepollfd, team[sub].fd, EPOLLIN || EPOLLET, &team[sub]);
        add_event_ptr(bepollfd, team[sub].fd, EPOLLIN || EPOLLET, &team[sub]);
    } else {
        add_event_ptr(bepollfd, team[sub].fd, EPOLLIN || EPOLLET, &team[sub]);
        
    }
} 
