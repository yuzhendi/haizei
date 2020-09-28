/*************************************************************************
	> File Name: 607.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月25日 星期六 17时16分27秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int n,num[105][105], dp[105][105];

int main() {
    int n;
    cin >>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j + 1], dp[i + 1][j]) + num[i][j];
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}
