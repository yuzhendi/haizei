/*************************************************************************
	> File Name: 13大整数加法.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月28日 星期一 09时53分09秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 52

char str[MAX_N + 5] = {0};
int ans[MAX_N + 5] = {0};

int main() {
    while(~scanf("%s", str)) {
        int len = strlen(str);
        if (len > ans[0]) ans[0] = len;
        for (int i = 0; i < len; i++) {
            ans[len - i] += str[i] - '0';
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    for (int i = ans[0]; i >= ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
