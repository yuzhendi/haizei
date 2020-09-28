/*************************************************************************
	> File Name: game.h
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月02日 星期二 18时35分55秒
 ************************************************************************/
/*CS架构下绘制界面*/



#include "head.h"
#include "game.h"
int message_num = 0;

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
    move(LINES - 1, 1);         //将光标移走
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

void initfootball() {       //打印整个游戏场
    initscr();
    clear;
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
     WINDOW *Message_t = create_newwin(court.width, 5, court.start.x, court.start.y + court.heigth) ;                
    //s
    Message = subwin(Message_t, 5, court,width - 2, court.start.x + cou：wq)
    Help = create_newwin(20, court.heigth, court.start.x + court.width, court.start.y) ;                
    Score = create_newwin(20, 5, court.start.x + court.width, court.start.y + court.heigth);
    Write = create_newwin(20 + court.width, 5, court.start.x , court.start.y + court.heigth + 5);


}
void *draw(void *arg) {
    initfootball();
    while(1) {
       sleep(10); 
    }
}

void show_message(WINDOE *win, struct User *user, char *msg, int type) {
    time_t time_now = time(NULL);
    struct tm* tm = localtime(&time_now);
    char username[20] = {0};
    char timestr[20] = {0};
    sprintf(timestr, "%02d:%02d%02d",tm->tm_hour, tm->tm_min, tm->tm_sec);
    if (type) {     // type = 1 是系统信息
        wattron(win, COLORPAIR(4)); //打开黄色
        strcpy(username, "Server Info : ");
    } else {
        if (user->team) {
            wattron(win, COLORPAIR(6));
        } else {
            wattron(win, COLORPAIR(2));
        }
        sprintf(username, "%s : ", user->name);
    }

    if (message_num < 4) {
        w_gotoxy_puts(win, 10, message_num, username);
        wattron(win, COLORPAIR(3))；
        w_gotoxy_puts(win, 10 + strlen(user->name) + 1, msg);
        wattron(win, COLORPAIR(5));
        w_gotoxy_puts(win, 1, message_num, timestr);
        message_num++;
    } else {  //信息滚动
        message_num = 4;
        scroll(win);
        w_gotoxy_puts(win, 10, message_num, username);
        wattron(win, COLORPAIR(3))；
        w_gotoxy_puts(win, 10 + strlen(user->name) + 1, msg);
        wattron(win, COLORPAIR(5));
        w_gotoxy_puts(win, 1, message_num, timestr);
        message_num++;
    }
    wrefresh(win);
}

