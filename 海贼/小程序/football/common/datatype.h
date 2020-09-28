/*************************************************************************
	> File Name: datatype.h
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月06日 星期六 20时24分13秒
 ************************************************************************/

#ifndef _DATATYPE_H
#define _DATATYPE_H
#define MAXMSG 1024
struct LogRequest {
    char name[20];
    int team;
    char msg[512];
};

struct LogResponse {
    int type; // 0: success  1: fail
    char msg[512];
};

struct Point {
    int x;
    int y;
};

struct User {
    int team;
    int online;
    int fd;
    char name[20];
    int flag;       //判断是否在线 UDP:未相应的次数
    struct Point loc;//位置
};
struct Map {
    int width;      //地图的宽
    int heigth;     //高
    struct Point start;     //开始的点
    int gate_width;         //球门的宽度
    int gate_heigth;        //球门的高度
};

struct Ctrl {
    int carry;      //带球
    int kick;       //踢球
};

struct TransMsg {       //传输的信息
    int dirx;
    int diry;      //两个方向
    struct Ctrl ctrl;
};
#define FT_TEST 0x01   // 测试在不再线
#define FT_WALL 0x02    //广播
#define FT_MSG 0x04
#define FT_ACK 0x08


struct FootBallMsg {
    int type;
    int size;
    char msg[MAXMSG];
};

#endif
