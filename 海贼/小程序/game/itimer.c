/*************************************************************************
	> File Name: itimer.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月31日 星期日 15时54分03秒
 ************************************************************************/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void print() {
    printf("Recv a signal!\n");
}
int main() {
    struct itimerval itm;
    signal(14, print);
    itm.it_interval.tv_sec = 1;
    itm.it_interval.tv_usec = 0;
    itm.it_value_tv_sec = 3;
    itm.it_value_tv_usec = 0;

    setitimer(ITIMER_REL, &itm, NULL);
    while (1) {
       // sleep(10);
    }

    return 0;
}
