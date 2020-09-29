/*************************************************************************
	> File Name: 42钱币问题.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月29日 星期二 10时31分57秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[25];
int ans[25][10005];
int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> arr[i];
        ans[i][0] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            ans[i][j] = ans[i - 1][j];
            if (j >= arr[i]) ans[i][j] += ans[i][j - arr[i]];
            ans[i][j] %= 9973;
        }
    } 
    cout << ans[m][n] << endl;

    return 0;
}
