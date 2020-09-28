/*************************************************************************
	> File Name: 228.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月24日 星期四 10时02分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define Inf 0x3f3f3f3f
int n;
int mmap[25][25];
int cnt = 1;
int dp[(1 << 21) + 5][25]; // dp[i][j] 表示i状态下1到j的最短距离， i的二进制位表示位走过的点
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> mmap[i][j];
    }
    cnt = (cnt << n) - 1; // 全1表示所有数均可以走
    memset(dp, Inf, sizeof(dp)); // 初始状态为全1
    dp[1][0] = 0; //  
    for (int i = 1; i <= (1 << n) - 1; i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) { // 可以经过 j 点
                for (int k = 0; k < n; k++) {
                    if ((i >> k) & 1) { // 以k为跳板，找到最小值
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + mmap[k][j]);
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << endl;
    return 0;
}
