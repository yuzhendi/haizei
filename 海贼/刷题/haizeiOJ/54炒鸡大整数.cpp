/*************************************************************************
	> File Name: 54炒鸡大整数.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月29日 星期二 15时10分02秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 1000000
int val[MAX_N + 5];
int ans[MAX_N + 5];
int main() {
    int x;
    while(scanf("%d",&x) != EOF) {
        memset(val, 0, sizeof(val));
        memset(ans, 0, sizeof(ans));
        val[0] = 1;
        val[1] = 1;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= val[0]; j++) {
                val[j] *= i;
            }
            for (int j = 1; j <= val[0]; j++) {
                if (val[j] < 10) continue;
                val[j + 1] += (val[j] / 10);
                val[j] %= 10;
                val[0] += (j == val[0]);
            }
        }
        ans[0] = 1; ans[1] = 1;
        for (int i = val[0]; i >= 1; i--) { // 遍历阶乘的结果
            if (val[i] == 0) continue;
            for (int j = 1; j <= ans[0]; j++) {
                ans[j] *= val[i];
            }
            for (int j = 1; j <= ans[0]; j++) {
                if (ans[j] < 10) continue;
                ans[j + 1] += (ans[j] / 10);
                ans[j] %= 10;
                ans[0] += (ans[0] == j);
            }
        }
        for (int i = ans[0]; i >= 1; i--) {
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
