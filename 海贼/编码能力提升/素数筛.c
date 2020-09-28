/*************************************************************************
	> File Name: 素数筛.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月11日 星期六 08时54分52秒
 ************************************************************************/

#include <stdio.h>
#define max_n 2000000

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i  <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            for (int j = 2; j * i <= max_n; j++) {
                prime[j * i] = 1;
            }
        }
    }
    return ;
}

int main() {
    init();
    printf("第1001个素数是:%d\n",prime[1001]);
    return 0;
}
