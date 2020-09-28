/*************************************************************************
	> File Name: 546摆花.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月20日 星期日 18时32分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int num[105];
int ans[105][105]; // ans[i][j] 表示前 i 种摆 j 盆的种类数

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i <= num[0]; i++) {
        ans[0][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= num[i]; k++) { // 从0开始，第一个要用到第0个的数据
                if (j - k < 0) break;
                ans[i][j] += ans[i - 1][j - k];
                ans[i][j] %= 1000007;
            }
        }
    }
    cout << ans[n - 1][m] << endl; 

    return 0;
}
