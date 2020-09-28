/*************************************************************************
	> File Name: 297.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月20日 星期日 18时52分57秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[55], a[55], ans;
int main() {
    dp[0] = dp[1] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (int j = i - 1; j > 0; j--) {
            if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1), f = 1;
        }
        if (f == 0) dp[i] = 1;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
