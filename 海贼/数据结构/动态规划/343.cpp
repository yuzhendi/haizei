/*************************************************************************
	> File Name: 343.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月02日 星期六 21时08分41秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 3000
int a[MAX_N + 5], b[MAX_N + 5];
int n;
int dp[MAX_N + 5][MAX_N + 5];
int main() {
    long long ans;
    cin >> n;
    int t = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (a[i] - b[j]) continue;
            for (int k = 1; k <= n; k++) {
                if (a[k] >= a[i]) continue;
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + 1);
            }
            ans =(ans > dp[i][j]) ? ans : dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
