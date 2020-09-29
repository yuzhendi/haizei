/*************************************************************************
	> File Name: 43数字三角形.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月29日 星期二 11时04分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
long long f[1005][1005];
long long val[1005][1005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + val[i][j];
        }
    }
    cout << f[1][1] << endl;

    return 0;
}
