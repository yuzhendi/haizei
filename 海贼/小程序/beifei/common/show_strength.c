/*************************************************************************
	> File Name: show_strength.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月30日 星期二 19时53分51秒
 ************************************************************************/

#include "head.h"
#include "game.h"
// 显示踢球的力度,并通过按键时机控制力度
//
extern int sockfd;
extern WINDOW *Write;

void show_strength() {
    int max_x, max_y, strength, mousex = 2, offset = 1;
    getmaxyx(Write, max_y, max_x);
    for (int i = 2; i < max_y - 2; i++) {
        if (i < max_y / 5 || i > max_y - max_y / 5) {
            wattron(Write, COLOR_PAIR(9));
        } else if (i < max_y / 5 * 2  || i > max_y - max_y / 5 * 2) {
            wattron(Write, COLOR_PAIR(8));
        } else {
            wattron(Write, COLOR_PAIR(10));
        }
        mvwprintw(Write, 2,i , " ");
    }
    wrefresh(Write);
    wattron(Write, COLOR_PAIR(3));
    make_nonblock(0);
    while(1) {
        char c = getchar();
        if (c != -1) {
            if (c == ' ' || c == 'k') {
                //
                break;
            }
        } else {
            // 
        }
        usleep(10000);
        if (mousex >= max_y - 2) {
            offset = -1;
        } else if (mousex <= 2){
            mousex = 2;
        }
        mousex += offset;
        mvwprintw(Write, 3, mousex, " ");
        wrefresh(Write);
    }
        int arr[] = {1, 2, 3, 2, 1};
        struct FootBallMsg msg;
        msg.type = FT_CTL;
        msg.ctl.action = ACTION_KICK;
        msg.ctl.strengh = arr[mousex / (max_x / 5)];
        send(sockfd, (void*)&msg, sizeof(msg), 0);

}
