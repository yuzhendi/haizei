/*************************************************************************
	> File Name: client.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月09日 星期二 20时40分05秒
 ************************************************************************/
#include "../common/head.h"
#include "../common/udp_client.h"
#include "../common/client_recver.h"
#include "../common/game.h"
char server_ip[20] = {0};
int server_port = 0;
int sockfd;
char *conf = "./football.conf";

void logout(int signum) {
    struct FootBallMsg msg;
    msg.type = FT_FIN;
    //printf("%d",msg.type);
    send(sockfd, (void *)&msg, sizeof(msg), 0);
    endwin();
    DBG(RED"logout!\n"NONE);
    exit(1);
}


int main(int argc, char **argv) {
    int opt;
    struct LogRequest request;
    struct LogResponse response;
    bzero(&request, sizeof(request));
    pthread_t recv_t, draw;
    while ((opt = getopt(argc, argv, "h:p:n:t:m:")) != -1) {
        switch(opt) {
            case 'h' :
                strcpy(server_ip, optarg);
                break;
            case 'p' :
                server_port = atoi(optarg);
                break;
            case 'n':
                strcpy(request.name, optarg);
                break;
            case 't':
                request.team = atoi(optarg);
                break;
            case 'm':
                strcpy(request.msg, optarg);
                break;
            default :
                fprintf(stderr, "Usage : %s [-h host] [-p port]\n", argv[0]);
            exit(1);
        }
    }

    argc -= (optind - 1);
    argv += (optind - 1);

    if (argc > 1) {
        fprintf(stderr, "Usage : %s [-h host] [-p port]!\n", argv[0]);
        exit(1);
    }
    
    if (!server_port) server_port = atoi(get_value(conf, "SERVERPORT"));
    if (!strlen(server_ip)) strcpy(server_ip, get_value(conf, "SERVERIP"));
    if (!strlen(request.name)) strcpy(request.name, get_value(conf, "NAME"));
    if (!strlen(request.msg)) strcpy(request.msg, get_value(conf, "LOGMSG"));
    if (!request.team) request.team = atoi(get_value(conf, "TEAM"));
    
   signal(SIGINT, logout);
    
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);
    server.sin_addr.s_addr = inet_addr(server_ip);

    socklen_t len = sizeof(server);

    
    DBG(GREEN"INFO"NONE" : server_ip = %s : server_port = %d, name = %s, team = %s, logmsg = %s\n", server_ip, server_port, request.name, (request.team ? "BLUE" : "RED"), request.msg);
    
    if ((sockfd = socket_udp()) < 0) {
        perror("socket_udp");
        exit(1);
    }

   //printf("71\n"); 
    sendto(sockfd, (void *)&request, sizeof(request), 0, (struct sockaddr *)&server, len);
    
    //设置5s超时
    fd_set set;
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    
    int retval = select(sockfd + 1, &set, NULL, NULL, &tv);
    if (retval == -1) {
        perror("select");
        exit(1);
    } else if (retval) {
        int ret = recvfrom(sockfd, (void *)&response, sizeof(response), 0, (struct sockaddr*)&server, &len);
        if (ret != sizeof(response) || response.type) {
            DBG(RED"ERROR : "NONE"The Game Server refused your login.\n\tThis May be helpfull ：%s\n",response.msg);
            exit(1);
        }
    } else {
        //超时
        DBG(RED"ERROR : "NONE" The Game Server is out of service.\n");
    }


    DBG(GREEN"SERVER : "NONE" %s \n", response.msg);
    connect(sockfd, (struct sockaddr *)&server, len);
   /* 
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    //子进程收数据
    if (pid == 0) {
        fclose(stdin);
        while (1) {
            struct FootBallMsg msg;
            //memset(msg.msg, 0, sizeof(msg.msg));
            bzero(&msg, sizeof(msg));
            ssize_t rsize = recv(sockfd, (void *)&msg, sizeof(msg), 0);
            if (msg.type & FT_TEST) {
                DBG(RED"HeartBeat from Server 心跳\n"NONE);
                msg.type = FT_ACK;
                send(sockfd, (void *)&msg, sizeof(msg), 0);
            } else if (msg.type & (FT_MSG | FT_WALL)) {
                DBG(GREEN"Server Msg : "NONE" %s \n", msg.msg);
            } else {
                DBG(GREEN"Server Msg : "NONE"Unsupport Message Type.\n");
            }
        }
    } else {
        //父进程发数据*/
#ifndef _D
        pthread_create(&draw, NULL, (void *)draw, NULL);
#endif
        pthread_create(&recv_t, NULL, client_recver, NULL);
        while (1) {
            struct FootBallMsg msg;
            bzero(&msg, sizeof(msg));
            //memset(msg.msg, 0, sizeof(msg.msg));
            //Show_Message( , )
            msg.type = FT_MSG;
            DBG(YELLOW"Input Message : "NONE);
            w_gotoxy_puts(Write, 1, 1, "Input Message : ");
            mvwscanw(Write, 2, 1, "%[^\n]s", msg.msg);
            scanf("%s[^\n]s", msg.msg);
            int l = strlen(msg.msg);
            if (!l) continue;
            getchar();
            send(sockfd, (void *)&msg, sizeof(msg), 0);
        }
    
    sleep(10);

    return 0;
}

