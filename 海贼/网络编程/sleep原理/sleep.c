/*************************************************************************
	> File Name: sleep.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月02日 星期三 10时12分07秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print() {
    printf("This is time over\n");
}
int main() {
    signal(14, print);
    alarm(10); // 10s后
    pause();
    return 0;
}

