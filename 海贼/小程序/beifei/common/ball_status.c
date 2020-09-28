/*************************************************************************
	> File Name: ball_status.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月02日 星期四 18时17分29秒
 ************************************************************************/

#include "head.h"
#include "game.h"
#include "./datatype.h"
#define PI 3.1415926
extern WINDOW *Message;
extern struct Bpoint ball;
extern struct BallStatus ball_status;

int aera(int x, int y) {
    return x * x + y * y;
}

int can_kick(struct Point *loc, int strength)  { // 传入球的初始位置和所收力度
   int  px = loc->x - 2, py = loc->y - 1;
    int ans = aera(px - (int)ball.x, py - (int)ball.y);
    if (ans != 0 && ans <= 4) {  // 半径 r = 2 以内可以进行踢球(同一个位置不能踢球)
        // 可以踢球
        int len = (pow(ball.x - px, 2) + pow(ball.y - py, 2) );
        double real_len = sqrt(len); // 斜边的长度
        double dx = (ball.x - px) / real_len; // 方向在x上的分量
        double dy = (ball.y - py) / real_len;

        ball_status.a.x = -3 * dx; // 阻力的加速度
        ball_status.a.y = -3 * dy;
        ball_status.v.x = strength * 0.2 * 40 * dx; // 加速度作用 0.2s
        ball_status.v.y = strength * 0.2 * 40 * dy; // 加速度作用 0.2s
        
        return 1;
    }
    return 0;

}
