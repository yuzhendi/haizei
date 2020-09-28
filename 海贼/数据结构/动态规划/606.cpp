/*************************************************************************
	> File Name: 606.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月25日 星期六 17时03分27秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int a[1005], dp[1005];

int main() {
    int n, ans = -9999;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1] + a[i],a[i]);
        if (ans < dp[i]) ans = dp[i];
    }
    cout << ans << endl;
}
