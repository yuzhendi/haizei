/*************************************************************************
	> File Name: B.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 19时41分55秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000
int f[MAX_N + 5][MAX_N + 5], val[25];
int n, m;
int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= m; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= val[i]) f[i][j] += f[i][j - val[i]];
            f[i][j] %= 9973;
        }
    }
    cout << f[m][n] << endl;
    return 0;
}
