/*************************************************************************
	> File Name: 2.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月31日 星期日 14时32分18秒
 ************************************************************************/

#include <stdio.h>
//#include <curese.h>
#include <unistd.h>
#include <time.h>
#define LEDTEDGE 10
#define RIGHTEDGE 70
#define ROW 10
/***********************/

int main() {
    char message[20] = "Hello HaiZei!";
    char black[20] = "              ";
    int pos = 0;
    int dir = 1;
    initscr();//初始化屏幕
    start_color();
    init_pari(1, COLOR_GREEN, COLOR_RED);//初始化颜色对(序号，fg，bg)
    while(1) {
        move(ROW, pos);
        attron(COLOR_PAIR(1));//开启属性
        addstr(message);
        attroff(COLOR_PAIR(1));
        move(LINES - 1, COLS - 1);//将光标移动到角落
        refresh();
        usleep(1000);
        move(ROW, pos);
        addstr(black);
        pos += dir;
        if (pos >= RIGHTEDGE) dir = -1;
        if (pos <= LEDTEDGE) dir = 1;
    }

    return 0;
}
