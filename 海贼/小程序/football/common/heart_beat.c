/*************************************************************************
	> File Name: heart_beat.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月09日 星期二 20时21分45秒
 ************************************************************************/

#include "head.h"
#include "datatype.h"
#define MAX 50
extern struct User *rteam, *bteam;

void heart_beat_team(struct User *team) {
    struct FootBallMsg msg;
    msg.type = FT_TEST;
    for (int i = 0; i < MAX; i++) {
        if (team[i].online) {
            if (!team[i].flag) { //下线
                team[i].online = 0;
               continue;
            }
            send(team[i].fd, (void *)&msg, sizeof(msg), 0);
        }
    }
}

void *heart_beat(void *arg) {
    while (1) {
        sleep(10);
        heart_beat_team(bteam);
        heart_beat_team(rteam);
    }
}
