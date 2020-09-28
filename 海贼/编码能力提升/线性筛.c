/*************************************************************************
	> File Name: 线性筛.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月11日 星期六 09时17分05秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 200000

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i; //新的素数
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (0 == (i % prime[j])) break; // 3 * 3 == 9
        }
    }
    return ;
}

int main() {
    init();
    printf("第1001个素数是：%d\n", prime[1001]);
    return 0;
}
