/*************************************************************************
	> File Name: server_cjson.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月05日 星期日 16时01分06秒
 ************************************************************************/

#include "../common/head.h"
#include "../common/game.h"
#include "../common/datatype.h"
#include <cjson/cJSON.h>

#define MAX 50
extern struct User *rteam;
extern struct User *bteam;
extern struct BPoint ball;
extern struct BallStatus ball_status;
extern struct Score score;

int add_player_to_cjson(struct User *user, cJSON *team) {
    if (user->online == 0) return 0;
    cJSON *player = cJSON_CreateObject();
    cJSON_AddItemToObject(team, "name", cJSON_CreateString(user->name));
    cJSON_AddItemToObject(team, "x", cJSON_CreateNumber(user->loc.x));
    cJSON_AddItemToObject(team, "y", cJSON_CreateNumber(user->loc.y));
}

char *creat_cjson_1() {
    char *cjson_str = NULL;

    cJSON *Root = cJSON_CreateObject(); // 根对象
    cJSON *R_team = cJSON_CreateArray(); // 存放玩家的信息的数组
    cJSON *B_team = cJSON_CreateArray(); // 存放玩家的信息的数组
    cJSON *Ball = cJSON_CreateObject(); // 存放球的位置信息
    
    cJSON_AddItemToObject(Root, "red", R_team); // 将数组和球两个对象放入根对象
    cJSON_AddItemToObject(Root, "blue", B_team); // 将数组和球两个对象放入根对象
    cJSON_AddItemToObject(Root, "ball", Ball);

    // 将球的信息加入json
    cJSON_AddItemToObject(Ball, "who", cJSON_CreateNumber(ball_status.t)); //此处用 0 1 表表示队伍
    cJSON_AddItemToObject(Ball, "name", cJSON_CreateString(ball_status.name));
    cJSON_AddItemToObject(Ball, "x", cJSON_CreateNumber(ball.x));
    cJSON_AddItemToObject(Ball, "y", cJSON_CreateNumber(ball.y));

    // 将在线的红对玩家的信息加入json

    for (int i = 0; i < MAX; i++) {
        if (rteam[i].online) {
            add_player_to_cjson(&rteam[i], R_team);
        }
        if (bteam[i].online) {
            add_player_to_cjson(&bteam[i], B_team);
        }
    }
    cjson_str = cJSON_Print(Root);
    return cjson_str;
}

char *creat_cjson_2() {
    cJSON *cjson_str = NULL;    
    cJSON *Root = cJSON_CreateObject();
    cJSON *Score = cJSON_CreateArray();
    
    cJSON_AddItemToObject(Root, "score", Score);
    cJSON_AddItemToObject(Score, "red", cJSON_CreateNumber(score.red));
    cJSON_AddItemToObject(Score, "blue", cJSON_CreateNumber(score.blue)); 
    
    int win = 0;

    char who[20];
    if (ball_status.t) {
        if (ball.x == 0) {
            cJSON_AddItemToObject(Root, "who", cJSON_CreateString("red"));
            win = 1;
        } else {
            cJSON_AddItemToObject(Root, "who", cJSON_CreateString("blue"));
        }
    } else {
        cJSON_AddItemToObject(Root, "who", cJSON_CreateString("blue"));
    }
    cJSON_AddItemToObject(Root, "name",cJSON_CreateString(ball_status.name));
    

}

