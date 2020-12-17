/*************************************************************************
	> File Name: itimer.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月02日 星期三 10时30分00秒
 ************************************************************************/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void print() {
    printf("Recv a signal!\n");
}

int main() {
    struct itimerval itm;
    signal(14, print); // 信号处理函数

    itm.it_interval.tv_sec = 1; // 间隔时间
    itm.it_interval.tv_usec = 0;
    itm.it_value.tv_sec = 3; // 第一次出发的时间
    itm.it_value.tv_usec = 0;
    
    setitimer(ITIMER_REAL, &itm, NULL);
    printf("start:\n");
    while(1){
        
    }
    return 0;
}
