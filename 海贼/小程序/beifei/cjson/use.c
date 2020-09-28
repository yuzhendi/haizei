/*************************************************************************
	> File Name: use.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月05日 星期日 15时05分08秒
 ************************************************************************/

#include "../common/head.h"
#include <cjson/cJSON.h>
char * creat_cjson() {
    char *cjson_str = NULL;
    char *user = "yuzhendi";
    cJSON *root = cJSON_CreateObject(); // 根对象
    cJSON *player = cJSON_CreateObject();
    cJSON *player1 = cJSON_CreateObject();
    cJSON *player2 = cJSON_CreateObject();
    cJSON *player3 = cJSON_CreateObject();

    cJSON *team = cJSON_CreateArray(); // 队伍的对象
    cJSON *ball = cJSON_CreateObject(); // 球的对象
    
    cJSON_AddItemToObject(team, "1",player1);
    cJSON_AddItemToObject(team, "2",player2);
    cJSON_AddItemToObject(team, "3",player3);
    cJSON_AddItemToObject(root, "red", team);
    cJSON_AddItemToObject(player1, "name", cJSON_CreateString("yuzhendi"));
    cJSON_AddItemToObject(player2, "x", cJSON_CreateNumber(12));
    cJSON_AddItemToObject(player3, "y", cJSON_CreateNumber(23));

    cJSON_AddItemToObject(root, "blue", team);
    cJSON_AddItemToObject(player1, "name", cJSON_CreateString("yuzhendi"));
    cJSON_AddItemToObject(player2, "x", cJSON_CreateNumber(29));
    cJSON_AddItemToObject(player3, "y", cJSON_CreateNumber(18));
    cJSON_AddItemToObject(team, "",player1);

    cJSON_AddItemToObject(root, "ball", ball);
    cJSON_AddItemToObject(ball, "who", cJSON_CreateString("red"));
    cJSON_AddItemToObject(ball, "name", cJSON_CreateString("yuzhendi"));
    cJSON_AddItemToObject(ball, "x", cJSON_CreateNumber(29));
    cJSON_AddItemToObject(ball, "y", cJSON_CreateNumber(18));

    cjson_str = cJSON_Print(root);
    //cJSON_Delete(root);
    return cjson_str;;
    
}

int main() {
    char *cjson_str = creat_cjson();
    printf("test:\n%s\n",cjson_str);
    return 0;
}
