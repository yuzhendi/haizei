/*************************************************************************
	> File Name: game.h
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月31日 星期日 16时25分27秒
 ************************************************************************/

#ifndef _GAME_H
#define _GAME_H
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#define X 70
#define Y 20

struct point {
    int x, y;
};

struct point Bpoint;//记录木板的位置(左上角)
struct point Opoint;//记录球的位置
struct point Bdir, Odir;//方向
int cx = (X - 2) / 2 + 1;
int cy = (Y - 2) / 2 + 1;
void gotoxy(int x, int y) {
    move(y, x);
}

void gotoxy_putc() {

}
void gotoxy_puts() {

}
void initfield() {
    mvaddch(0, 0, '0');//移动到(0, 0)
    mvaddch(0, X, 'X');//移动到(0, 0)
    mvaddch(Y, 0, 'Y');//移动到(0, 0)
    for (int i = 1; i < X; i++) {
        mvaddch(1, i, '-');
        mvaddch(Y - 1, i, '-');
    }
    for (int i = 1; i < Y; i++) {
        mvaddch(i, 1, '|');
        mvaddch(i, X - 1, '|');
    }
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    gotoxy_puts(2, Y + 3, "Message:");
    gotoxy_puts(X + 3, 3, "help:");
}

void initgame() {//初始化游戏界面
    if (!has_colors() || start_color() == ERR) {
        endwin();
        fprintf(stderr, "终端不支持颜色!\n");
        exit(1);
    }
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    initfield(X, Y);
    Bpoint.x = cx - 3;
    Bpoint. = y - 3;

     for (int i = 0; i < 6; i++) {
        
    } 
    refresh();
}
void drawgame() {
    gotoxy_putc(Opoint.x, Opoint.y, ' ');//删除前面的球

    Opoint.x += Odir.x;
    Opoint.y += Odir.y;
    attron(COLOR_PAIR(2));
    for (int i = 0; i < 8; i++) {//删除板子
        gotoxy_putc(Bpoint.x + i, Bpoint.x, ' ');
        gotoxy_putc(Bpoint.x + i, Bpoint.x + 1. ' ');
    }
    attroff(COLOR_PAIR(2));
    
    Bpoint.x += Bdir.x;
    Bpoint.y += Bdir.y;
    
    memset(&Bdir, 0, sizeof(Bdir));//清空，防止朝一个方向一直移动
    if (Bpoint.x >= x - 8) Bpoint.x -= x - 8;
    if (Bpoint.x <= 2) Bpoint.x = 2;
    attron(COLOR_PAIR(3));
    for (int i = 0; i < 8; i++) {//清楚原来的板子
        gotoxy_putc(Bpoint.x + i, Bpoint.y, ' ');
        gotoxy_putc(Bpoint.x + i, Bpoint.y + 1, ' ');
    }
    attroff(COLOR_PAIR(3));
    refresh();

}

#endif
