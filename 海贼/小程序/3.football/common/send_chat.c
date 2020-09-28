/*************************************************************************
	> File Name: send_chat.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月14日 星期日 16时51分49秒
 ************************************************************************/

#include "head.h"
#include "game.h"
extern int sockfd;
extern WINDOW *Write;
extern struct FootBallMsg chat_msg;

void send_chat() {
    echo();
    nocbreak();  //再打开行缓冲
    bzero(chat_msg.msg, sizeof(chat_msg.msg));
    w_gotoxy_puts(Write, 1, 1, "Input Message : ");
    mvwscanw(Write, 2, 1, "%[^\n]s", chat_msg.msg);
    if (strlen(chat_msg.msg)) {
        send(sockfd, (void *)&chat_msg, sizeof(chat_msg), 0);
        mvwprintw(Write ,2, 1, "                                 ");
        mvwprintw(Write, 2, 2, " ");
    }
    //wclear(Write);
    
    //wrefresh(Write);
    
    noecho();
    cbreak();
}
