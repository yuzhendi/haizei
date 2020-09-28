/*************************************************************************
	> File Name: carry_ball.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月04日 星期六 15时38分19秒
 ************************************************************************/

#include "head.h"
#include "game.h"
#include "datatype.h"
#include "./ball_status.h"

extern struct BPoint ball; // 球
extern struct BallStatus ball_status;
// 判断是否可以带球， 
void carry_ball(struct Point *loc, char *name, int team) { // 传入带球人的名字和队伍
    if (can_kick(loc, 0)) {  // 球员在球的有效范围内
        if (ball_status.carry == 0 || strcmp(name, ball_status.name) == 0) { // 球是本人带或者没人带的时候才能跟着球员运动
            ball_status.carry = 1 ;// 有人带球
            
            strcpy(ball_status.name, name);
            ball_status.t = team;
            ball.x = loc->x + 1;
            ball.y = loc->y + 2;                                                           //   from 22 -> 23????


            ball_status.a.x = 0;  //加速度为 0
            ball_status.a.y = 0; 
            ball_status.v.x = 0;    
            ball_status.v.y = 0; // 速度为 0
        }
    }
    return ;
}

