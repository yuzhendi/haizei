/*************************************************************************
	> File Name: recv_cjson.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月05日 星期日 19时12分12秒
 ************************************************************************/

#include "../common/head.h"
#include "../common/game.h"
#include "../common/datatype.h"
#include "../common/server_re_draw.h"
#include <cjson/cJSON.h>
extern struct WINDOW *Football, *Football_t;
extern struct Score score;
extern struct BPoint ball;

void show_player(cJSON *Root) {
    cJSON *object = NULL;
   cJSON *F1 = cJSON_GetObjectItem(Root, "red"); // 获取数组对象
    int size = cJSON_GetArraySize(F1); // 获取数组对象的个数
    cJSON *arr_item = F1->child;
    for (int i = 0; i < size; i++) {
        // 读取红队的信息

        int x = cJSON_GetArrayItem(arr_item, "x")->valueint;
        int y = cJSON_GetArrayItem(object, "y")->valueint;
        char *name = cJSON_GetArrayItem(object, "name")->valuestring;
        wattron(Football, COLOR_PAIR(6));
        w_goxy_putc(Football, x, y, 'K');
        w_goxy_puts(Football, x, y, name);

        arr_item = arr_item->child;  // 下一个子对象
    }
    i = 0;
    while(cJSON *b = cJSON_GetArrayItem(Root->B_team, i)) {
        int x = cJSON_GetArrayItem(object, "x")->valueint;
        int y = cJSON_GetArrayItem(object, "y")->valueint;
        char *name = cJSON_GetArrayItem(object, "name")->valuestring;
        wattron(Football, COLOR_PAIR(2));
        w_goxy_putc(Football, x, y, 'K');
        w_goxy_puts(Football, x, y, name);
        i++ ;     
    }
    //  展示球
    cJSON *ball = cJSOn_GetObjectItem(Root, "ball");
    char *who = cJSON_GetObjectItem(ball, "who")->valuestring;
    char *name = cJSON_GetObjectItem(ball, "name")->valuestring;
    int x = cJSON_GetObjectItem(ball,"x")->valueint;
    int y = cJSON_GetObjectItem(ball,"p")->valueint;
    if (strcmp(who, "red") == 0) {
        // 红队带球，将球变成红色
        wattron(Football, COLOR_PAIR(6));
    }
    w_goxy_putc(Football_t, x, y, 'O');
    return ;
}

void show_score(cJSON *Root) {
    
}

void recv_cjson(char *message, int type) { 
    cJSON *Root = cJSON_Parse(message); // 将字符串打包成cJSON数据格式
    if (Root == NULL) {
        fprintf(stderr, "json pack into cjson erroe...");
        exit(1);
    } 
    if (type == 0) {
        // 解析球场信息
        show_player(Root);
    } else {
        //解析分数的信息
        show_score(Root);
    }

    return ;
}
