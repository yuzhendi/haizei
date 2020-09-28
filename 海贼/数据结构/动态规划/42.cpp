/*************************************************************************
	> File Name: 42.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月28日 星期二 18时36分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_M 20
#define MAX_N 10000
int f[MAX_M +5][MAX_N + 5];
int n, m;
int val[MAX_M + 5];
int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= m; i++) {
        f[i][0] = 1;//j = val[i]的时候You一种情况
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= val[i]) f[i][j] += f[i][j - val[i]];
            f[i][j] %= 9973;
        }
    }
    cout << f[m][n] << endl;
    return 0;
}
