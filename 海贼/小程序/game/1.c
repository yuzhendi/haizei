/*************************************************************************
	> File Name: 1.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月31日 星期日 14时12分15秒
 ************************************************************************/

#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main() {//字符移动
    initscr();
    for (int i = 0; i < LINES; i++) {
        move(i, i + 1);
        if (i % 2 == 0) {
            standout();//高亮
        }
        addstr("Hello HaiZei!");
        sleep(1);
        move(LINES, COLS);
        refresh();//刷新显示
        move(i - 1, i);
        addstr("             ");
        move(LINES - 2, COLS - 2);//删除上次显示的符号
        refresh();
    }
        getchar();
    
    endwin();//还原终端
    return 0;
}
