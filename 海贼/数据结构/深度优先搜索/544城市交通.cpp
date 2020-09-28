/*************************************************************************
	> File Name: 544城市交通.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月19日 星期六 20时57分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int a[105][105], ans = 0x3fffffff;
int n, check[105];

void dfs(int loc, int sum) {
    if (sum >= ans) return ;
    if (loc == n) {
        ans = min(ans, sum);
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0 && a[i][loc]) {
            check[i] = 1;
            dfs(i, sum + a[i][loc]);
            check[i] = 0;
        }
    }
}

int main() {
    cin >> n ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(1, 0);
    cout << ans << endl;


    return 0;
}
