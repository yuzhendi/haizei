/*************************************************************************
	> File Name: 538.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月17日 星期四 19时30分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 25
int a[MAX_N][MAX_N];
int ans[MAX_N], flag;
int n;
int check[MAX_N];

void dfs(int x) {
    if (flag) cout << "-";
    flag = 1;
    cout << x;
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        if (a[x][i] == 1) {
            check[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            dfs(i);
        }
    }
    return 0;
}
