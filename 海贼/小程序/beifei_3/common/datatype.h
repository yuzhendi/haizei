/*************************************************************************
	> File Name: datatype.h
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Jun 2020 08:23:55 PM CST
 ************************************************************************/

#ifndef _DATATYPE_H
#define _DATATYPE_H
#define MAXMSG 1024 
struct LogRequest{
    char name[20];
    int team; //0 RED 1 BLUE
    char msg[512];
};

struct LogResponse{
    int type; //0 success 1 failed
    char msg[512];
};

struct Point{
    int x;
    int y;
};

struct User{
    int team;
    int fd;
    char name[20];
    int online;
    int flag; // 未响应次数
    struct Point loc;
};

struct Map {
    int width;
    int heigth;
    struct Point start;
    int gate_width;
    int gate_heigth;
};

struct Ctrl {
    int carry; // 带球操作
    int kick; // 踢球操作
    int dirx;
    int diry;
};

struct TransMsg{
    int dirx;
    int diry;
    struct Ctrl ctrl;
};


#define FT_TEST 0x01  // 服务端心跳信息
#define FT_WALL 0x02  //服务端以字符串方式
#define FT_MSG 0x04  // 
#define FT_ACK 0x08
#define FT_FIN 0X10  // 客户端或者服务端下线通知
#define FT_CTL 0x20  //客户端发送的控制信息json
#define FT_GAME 0x40 //服务端向客户端发送的游戏实时图画 json发送
#define FT_SCORE 0x80 // 
#define FT_GAMEOVER 0x100  //游戏结束
struct FootBallMsg {
    int type;
    int size;
    int team;
    char name[80];
    char msg[MAXMSG];
    struct Ctrl ctl;
};

#endif
