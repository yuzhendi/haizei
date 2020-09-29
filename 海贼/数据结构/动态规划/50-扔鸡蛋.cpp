/*************************************************************************
	> File Name: 50-扔鸡蛋.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月29日 星期二 14时52分59秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 32
#define MAX_K 65536
int dp[MAX_N + 5][MAX_K + 5];//dp[i][j] 表示i个鸡蛋测j次最少测得的楼数
int main() {
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << m << endl;
    }
    for (int i = 2; i<= n; i++) {
        for (int j = 1; dp[i][j - 1] < m; j++) {
            long long val;
            if (i - 1 == 1) val = j - 1;// 测一次就碎的情况,转换为1个鸡蛋测j-1次最多可测的的楼数
            else  val = dp[i - 1][j - 1];
            dp[i][j] = val + dp[i][j - 1] + 1;// 加上不碎的情况和此次的楼层数
        }
    }
    int k = 1;
    while(dp[n][k] < m) k++;
    cout << k << endl;
    return 0;
}
