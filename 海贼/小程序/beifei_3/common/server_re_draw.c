/*************************************************************************
	> File Name: server_re_draw.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月14日 星期日 20时30分28秒
 ************************************************************************/

#include "head.h"
#include "game.h"

#define MAX 50
extern struct User *bteam, *rteam;
extern WINDOW *Football;

void re_draw_player(int team, char *name, struct Point *loc) {
    char p = 'K';
    if (team) {
        wattron(Football, COLOR_PAIR(6)); // 颜色  蓝
    } else {
        wattron(Football, COLOR_PAIR(2)); // 红
    }
    w_gotoxy_putc(Football, loc->x, loc->y, p); // 显示人的位置
    w_gotoxy_puts(Football, loc->x + 1, loc->y - 1, name); //右上角显示名字
}

void re_draw_team(struct User *team) {
    for (int i = 0; i < MAX; i++) {
        if (!team[i].online) continue;
        re_draw_player(team[i].team, team[i].name, &team[i].loc);
    }
}

void re_draw() { // 全部重绘界面
    wclear(Football);
    re_draw_team(rteam);  //重绘
    re_draw_team(bteam);
    box(Football, 0, 0);
}

