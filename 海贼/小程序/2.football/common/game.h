/*************************************************************************
	> File Name: game.h
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月02日 星期二 18时35分55秒
 ************************************************************************/
/*CS架构下绘制界面*/

#ifndef _GAME_H
#define _GAME_H
#define DEFARG(name, default_value, ((#name[0]) ? (name + 0) : default_value))

#define Show_Message(arg0, arg1, arg2, arg3) show_message(DEFARG(arg0, Message), DEFARG(arg1, NULL), arg2, DEFARG(arg3, 0))

#define MAX 50

struct Map court;
WINDOW *Football, *Message, *Help, *Score, *Write;
WINDOW *create_newwin(int width, int heigth, int startx, int starty) ;            //创建一个窗口
void destroy_win(WINDOW *win) ;
void gotoxy(int x, int y) ;
void gotoxy_putc(int x, int y, int c) ;
void gotoxy_puts(int x, int y, char *s) ;
void w_gotoxy_putc(WINDOW *win, int x, int y, int c) ;
void *draw(void *argv);
void show_message(WINDOW *win, struct User *user, char *msg, int type);
#endif
