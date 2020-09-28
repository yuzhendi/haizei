/*************************************************************************
	> File Name: luo.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月04日 星期四 18时54分35秒
 ************************************************************************/


#include "../common/color.h"
#include "../common/head.h"
#include "../common/common.h"
#include "./game.h"
#include "../common/udp_server.h"
char *conf = "./server.conf";
struct User *rteam;
struct User *bteam;
struct Map court;

int main(int argc, char **argv) {
    int opt, port = 0, listener, data_port;
    pthread_t draw_t; 
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p':
            port = atoi(optarg);
            break;
            default:
                fprintf(stderr, "Usage: %s[-p port]\n",argv[0]);
                exit(1);
                break;
        }
    }
    argc -= (optind - 1);
    argv += (optind - 1);
    if (argc > 1) {
        fprintf(stderr, "Usage: %s[-p port]\n",argv[0]);
        exit(1);
    }
    if (!port) port = atoi(get_value(conf,"PORT"));
    data_port = atoi(get_value(conf,"DATAPORT"));
    court.width = atoi(get_value(conf, "COLS"));
    court.heigth = atoi(get_value(conf, "LINES"));
    court.start.x = court.start.y = 1;
    rteam = (struct User *)calloc(MAX, sizeof(struct User));
    bteam = (struct User *)calloc(MAX, sizeof(struct User));


    if ((listener = socket_create_udp(port)) < 0) {
        perror("socket_create_udp");
        exit(1);
    }
    DBG(GREEN"INFO"NONE": Server start on Port %d\n", port);
    pthread_create(&draw_t, NULL, draw, NULL);
    int epoll_fd;
    epoll_fd = epoll_create(MAX * 2);
    if (epoll_fd < 0) {
        perror("epoll_create");
        exit(1);
    }

    struct epoll_event ev, events[MAX * 2];
    struct LogData lg;
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    ev.events = EPOLLIN;
    ev.data.fd = listener;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listener, &ev);
    while (1) {
        w_gotoxy_puts(Message,1,1,"等待连接");
        int nfds = epoll_wait(epoll_fd, events, MAX * 2, -1);
        for (int i = 0; i < nfds; i++) {
            char info[1024] = {0};
            recvfrom(events[i].data.fd, (void *)info, sizeof(info), 0, (struct sockaddr *)&client, &len);
            sprintf(info,"Login : %s : %d", inet_ntoa(client.sin_addr),ntohs(client.sin_port));
            w_gotoxy_puts(Message, 1, 2, info);
        }

    }


    return 0;

}
