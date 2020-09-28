/*************************************************************************
	> File Name: game.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月31日 星期日 16时26分15秒
 ************************************************************************/

#include "game.h"

int main() {
    initscr();
    noecho();//非阻塞
    cbreak();
    keypad(stdscr, TRUE);//打开功能键
    initgame();//绘制界面
    
    signal(14, drawgame);

    struct itimerval itimer;
    itimer.it_interval_sec = 10;
    itimer.it_inter.tv.tv_usec = 100000;
    itimer.it_value.tv_sec = 10;
    itimer.it_value.tv_usec = 1000;

    setitimer(ITIMER_REAL, &itimer, NULL);//打开计时器

    while(1) {
        int c = getchar();
        switch(c) {
            case KEY_LEFT:
                Bdir.x -= 2;
                break;
            case KEY_RIGHT:
                Bdir += 2;
                break;
            case KEY_UP :
                break;
            default:
                break;
        }
    }
    getchar();
    endwin();

    return 0;
}

