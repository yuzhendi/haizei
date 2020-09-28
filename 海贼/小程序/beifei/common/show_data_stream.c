/*************************************************************************
	> File Name: show_data_stream.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月30日 星期二 19时23分04秒
 ************************************************************************/

#include "head.h"
#include "game.h"
extern WINDOW *Help;
extern char data_stream[20];
extern struct Map court;

void show_data_stream(char type) { // t  c s  n e
    for (int i = 18; i > 1; i--) {
        data_stream[i] = data_stream[ i - 1 ];
    }
    data_stream[0] = type;
    for (int i = 1; i < 19; i++) {
        switch(data_stream[i]) {
            case 't': wattron(Help, COLOR_PAIR(7));break;
            case 'c': wattron(Help, COLOR_PAIR(8));break;
            case 's': wattron(Help, COLOR_PAIR(9));break;
            case 'n': wattron(Help, COLOR_PAIR(10));break;
            case 'e': wattron(Help, COLOR_PAIR(11));break;
        }
        
        mvwprintw(Help, court.heigth, i, " ");
    }
    wrefresh(Help);
}
