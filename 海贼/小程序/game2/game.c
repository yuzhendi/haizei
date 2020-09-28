/*************************************************************************
	> File Name: game.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月31日 星期日 19时23分30秒
 ************************************************************************/

#include "./game.h"
int main() {
    initscr();
    noecho();
    cbreak();//行缓冲改单个字符
    keypad(stdscr, TRUE);
    initgame();


    signal(14, drawgame);

    struct itimerval itimer;
    itimer.it_interval.tv_sec = 0;
    itimer.it_interval.tv_usec = 100000;
    itimer.it_value.tv_sec = 0;
    itimer.it_value.tv_usec = 1000;

    setitimer(ITIMER_REAL, &itimer, NULL);
   // attron(COLOR_PAIR(4));
    //gotoxy_putc(Opoint)
   while (1) {
        int c = getch();
        switch(c) {
            case KEY_LEFT:
               Bdir.x -= 2;
               break;
            case KEY_RIGHT:
                Bdir.x += 2;
                break;
            case KEY_UP:
                if (flag) break;
                flag = 1;
                Odir.x = dirx[get_random(2)];
                Odir.y = -1;
                //if (Odir.y > )
                break;
            default:
                break;
        }
    }
    
    getchar();
    endwin();
    return 0;

}
