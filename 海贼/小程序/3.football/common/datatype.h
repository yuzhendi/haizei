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
    int carry;
    int kick;
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
    int num; // 下标
    struct Ctrl ctl;
};

struct Elf {  //球场的运动员
    int online;  // 0 表示没有分配
    int fd;  //分配给用户的fd
    int num;  // 内部编号
    int team;  // blue: 1
    struct Point now;  // 目前所在位置
}

#endif
