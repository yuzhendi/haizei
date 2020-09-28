/*************************************************************************
	> File Name: sleep.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月31日 星期日 15时04分06秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print() {
    printf("Ti's time out!\n");
}
int main() {
    signal(14,print);
    alarm(10);//睡眠10s
    pause();
    

    return 0;
}
