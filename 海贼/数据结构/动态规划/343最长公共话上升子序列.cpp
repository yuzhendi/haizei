/*************************************************************************
	> File Name: 343最长公共话上升子序列.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月25日 星期五 22时04分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 3000
int a[MAX_N + 5], b[MAX_N + 5];
int n, ans;
int dp[MAX_N + 5][MAX_N + 5];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++) {
        cin >> b[j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j]; // dp[i][j] 表示以a[i]结尾的最长公共上升子序列
            if (a[i] - b[i]) continue; // a[i] != b[j] 的时候
            dp[i][j] = max(1, dp[i][j]);
            for (int k = 1; k < i; k++) {
                if (a[k] >= a[i]) continue;
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
