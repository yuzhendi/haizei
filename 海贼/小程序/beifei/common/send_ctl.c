/*************************************************************************
	> File Name: send_ctl.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月14日 星期日 20时07分59秒
 ************************************************************************/

#include "head.h"
extern int sockfd;
extern struct FootBallMsg ctl_msg;

void send_ctl() {
    if (ctl_msg.ctl.dirx || ctl_msg.ctl.diry) { // 有控制信息的话
        send(sockfd, (void *)&ctl_msg, sizeof(ctl_msg), 0);
    }
    ctl_msg.ctl.dirx = ctl_msg.ctl.diry = 0;// 再初始化
}
