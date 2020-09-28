/*************************************************************************
	> File Name: server_re_draw.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月14日 星期日 20时30分28秒
 ************************************************************************/
#include "head.h"
#include "game.h"
#define MAX 50
extern struct User *rteam, *bteam;
extern WINDOW *Football, *Football_t;
extern struct BPoint ball;
extern struct BallStatus ball_status;
extern struct Score score;

void re_drew_player(int team, char *name, struct Point *loc) {
    char p = 'K';
    if (team) {
        wattron(Football, COLOR_PAIR(6));
    } else {
        wattron(Football, COLOR_PAIR(2));
    }
    w_gotoxy_putc(Football, loc->x, loc->y, p);
    w_gotoxy_puts(Football, loc->x + 1, loc->y - 1, name);

}

void re_drew_team(struct User *team) {
    for (int i = 0; i < MAX; i++) {
        if (!team[i].online) continue;
        re_drew_player(team[i].team, team[i].name, &team[i].loc);
    }
}

extern double pre_vx, pre_vy; // 记录初始的速度
void re_draw_ball() {
    double t = 0.1;
    if (pre_vx * ball_status.v.x < 0 || pre_vy * ball_status.v.y < 0) {
        // 速度方向改边， 球停止
        ball_status.v.x = 0;
        ball_status.v.y = 0;
        ball_status.a.x = 0;
        ball_status.a.y = 0;
    }
    if (ball_status.v.x != 0 || ball_status.v.y != 0) {
        // 有速度, 球进行运动
        ball.x = ball.x + ball_status.v.x * 0.1 + ball_status.a.x * 0.5 * 0.1;
        ball.y = ball.y + ball_status.v.y * 0.1 + ball_status.a.y * 0.5 * 0.1;
        ball_status.v.x += ball_status.a.x * 0.1;
        ball_status.v.y += ball_status.a.y * 0.1;
    }
    if (ball.x <= 0 || ball.x > court.width || ball.y <= 0 || ball.y > court.heigth ) { // 球出边界的时候
        w_gotoxy_putc(Football_t, court.width / 2, court.heigth / 2, 'O'); // 初始化球的状态
        
       if (ball_status.t == 0) {
            score.red += 1; //蓝队出界，红对得分                                                                                   
       } else {
           score.blue += 1;
       }                                                                                    
        
        ball_status.v.x = 0;
        ball_status.v.y = 0;
        ball_status.a.x = 0;
        ball_status.a.y = 0;
        ball_status.t = -1;
        ball_status.carry = 0;
        pre_vx = 0;
        pre_vy = 0;
        memset(ball_status.name,0, sizeof(ball_status.name) );
        strcpy(ball_status.name, "");
        return ;
    }
    if ((ball.x == 0 && (ball.y >= court.heigth / 2 - 3 && ball.y <= court.heigth / 2 + 3)) || (ball.x == court.width && (ball.y >= court.heigth / 2 - 3 && ball.y <= court.heigth / 2 + 3))) {
        // 进球的情况
        if (ball_status.carry == 1) {
            // 有人带球进入球门， 扣分
            if (ball_status.t == 1) {
                score.blue += 1;
            } else {
                score.red += 1;
            }
        } else {
            if (ball_status.t != 1) {
                score.blue += 1;
            } else {
                score.red += 1;

        }
        w_gotoxy_putc(Football_t, court.width / 2, court.heigth / 2, 'O'); // 初始化球的状态
        ball_status.v.x = 0;
        ball_status.v.y = 0;
        ball_status.a.x = 0;
        ball_status.a.y = 0;
        ball_status.t = -1;
        ball_status.carry = 0;
        pre_vx = 0;
        pre_vy = 0;
        memset(ball_status.name,0, sizeof(ball_status.name) );
        strcpy(ball_status.name, "");
        return ;
        }
    }
    w_gotoxy_putc(Football_t,(int)ball.x, (int)ball.y, 'O');
}

void re_drew() {
    wclear(Football_t);
    re_draw_ball();
    re_drew_team(rteam);
    re_drew_team(bteam);
    box(Football, 0, 0);
    box(Football, 0, 0);
    wrefresh(Football_t);
    //wrefresh(Football);
}
