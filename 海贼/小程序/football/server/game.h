/*************************************************************************
	> File Name: game.h
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月04日 星期四 18时59分09秒
 ************************************************************************/
#ifndef _GAME_H
#define _GAME_H

#define MAX 50
#include <curses.h>

struct LogData {
    char name[20];
    int team; // 0 :red,  1 : blue
};

struct Point {
    int x;
    int y;
};

struct User {
    int team;
    char name[20];
    int flag;       //判断是否在线
    struct sockaddr_in addr;
    struct Point loc;
};
struct Map {
    int width;      //地图的宽
    int heigth;     //高
    struct Point start;     //开始的点
    int gate_width;         //球门的宽度
    int gate_heigth;        //球门的高度
};

struct Ctrl {
    int carry;      //带球
    int kick;       //踢球
};

struct TransMsg {       //传输的信息
    int dirx;
    int diry;      //两个方向
    struct Ctrl ctrl;
};

struct Map court;
WINDOW *Football, *Message, *Help, *Score, *Write;
WINDOW *create_newwin(int width, int heigth, int startx, int starty) {
            //创建一个窗口
    WINDOW *win;
    win = newwin(heigth, width, starty, startx); // nurses库 [y,x]反者来的
    box(win, 0, 0); // 从【0，0】加
    wrefresh(win);
    return win;
}

void destroy_win(WINDOW *win) {
    wborder(win, ' ', ' ',' ', ' ', ' ', ' ',' ', ' '); //8ge 空格删除线
    wrefresh(win);
    delwin(win);
}

void gotoxy(int x, int y) {
    move(y, x);
}

void gotoxy_putc(int x, int y, int c) {
    move(y, x);
    addch(c);
    move(LINES - 1, 1);         //将光标移走，不影响美观
    refresh();
}
void gotoxy_puts(int x, int y, char *s) {
    move(y, x);
    addstr(s);
    move(LINES - 1, 1);
    refresh();
}

void w_gotoxy_putc(WINDOW *win, int x, int y, int c) {
    mvwaddch(win, y, x, c);
    move(LINES - 1, 1);
    wrefresh(win);
    return ;
}
void w_gotoxy_puts(WINDOW *win, int x, int y, char *s) {
    mvwprintw(win, y, x, s);
    move(LINES - 1, 1);
    wrefresh(win);
    return ;
}

void initfootball() {
    initscr();
    clear();
    if (!has_colors() || start_color() == ERR) {
        endwin();
        fprintf(stderr, "终端不支持颜色!\n");
        exit(1);
    } 
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);

                    
    Football = create_newwin(court.width, court.heigth, court.start.x, court.start.y) ;  //绘画一个球场边框              
    Message = create_newwin(court.width, 5, court.start.x, court.start.y + court.heigth) ;                
    Help = create_newwin(20, court.heigth, court.start.x + court.width, court.start.y) ;                
    Score = create_newwin(20, 5, court.start.x + court.width, court.start.y + court.heigth);
    Write = create_newwin(20 + court.width, 5, court.start.x , court.start.y + court.heigth + 5);

    move(LINES - 1, 1);

}
void *draw(void *arg) {
    initfootball();
    refresh();
    while(1) {
       sleep(10); 
    }
}

#endif
