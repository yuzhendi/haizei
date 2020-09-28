/*************************************************************************
	> File Name: 16大整数乘法.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月28日 星期一 10时00分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#define MAX_N 400
using namespace std;

int ans[MAX_N + 5] = {1, 1, 0};

int main() {
    for (int i = 0; i < 100; i++) {
        //for (int j = 1; j <= ans[0]; j++) ans[j] *=  2;
        for (int j = 1; j <= ans[0]; j++) ans[j] *=  1024;
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= ans[0]; i++) {
        sum += ans[i];
    }
    cout << sum << endl;


    return 0;
}
