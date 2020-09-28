/*************************************************************************
	> File Name: test1.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月30日 星期六 19时30分40秒
 ************************************************************************/

#include <stdio.h>
#include <curses.h>
#include <time.h>
#define len 105
#define row 25
#define door_len 6
#define door_row 8
void prit_rec();
void pri_door();
void go();
int main() {
    initscr();
    clear();
    prit_rec();//打印外部边框架
    pri_door();
    move(10, 15);
   // addstr("hello word!\n");
    addstr("0");
    go();
    refresh();
    getchar();
    getchar();
    while(1);
    //printf("hello word\n");

    endwin();
    return 0;
}
void go() {
    for (int i = 5; i < 10; i++) {
        for (int j = 5; j < 18; j++) {
            move(i,j);
            addstr("0");
           // getchar();
            sleep(1);
            refresh();
            move(i,j);
            addstr(" ");
        }
    }
}
void pri_door() {
    /*****打印  -----   ***********/
    for (int i = 1; i < door_len; i++) {
        int ind = row >> 1;
        int l = door_row >> 1;
        move(ind - l, i);
        addstr("-");
        move(ind + l, i);
        addstr("-");
        
    }
    for (int i = len - door_len; i < len; i++) {
        int ind = door_row >> 1;
        int l = door_row >> 1;
        move(ind - l, i);
        addstr("-");
        move(ind + l, i);
        addstr("-");
    }
    /**** 打印  ||||||||   ******/
        int ind = door_row >> 1;
        int l = door_row >> 1;

}

void prit_rec() {
    for (int i = 0; i < len; i++) {
        // 65 * 105
        move(0,i);
        addstr("-");
        move(row - 1, i);
        addstr("-");
    }
    for (int j = 1; j < row - 1; j++) {
        move(j,0);
        addstr("|");
        move(j, len >> 1);
        addstr("|");
        move(j, len - 1);
        addstr("|");
    }
    

    return;
}
