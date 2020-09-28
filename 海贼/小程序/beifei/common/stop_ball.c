/*************************************************************************
	> File Name: stop_ball.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月04日 星期六 15时19分15秒
 ************************************************************************/

#include "head.h"
#include "./game.h"
#include "./datatype.h"
#include "./ball_status.h"
extern WINDOW *Football, *Football_t;
extern struct BPoint ball;
extern struct BallStatus ball_status;
// 判断是否可以进行停球操作，可以就停球
void stop_ball(struct Point *loc) { // 传入人的位置
    if (can_kick(loc, 0)) {
        // 可以踢球 ， 表示可以停球
        ball.x = ball.x;
        ball.y = ball.y;
        ball_status.a.x = 0;  // 加速度= 0
        ball_status.a.y = 0;  // 加速度= 0
        ball_status.v.x = 0; // 速度 v = 0
        ball_status.v.y = 0; // 速度 v = 0
    }
    w_gotoxy_putc(Football, ball.x, ball.y, 'O');
}
