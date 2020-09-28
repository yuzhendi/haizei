/*************************************************************************
	> File Name: 4779.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月12日 星期五 19时28分23秒
 ************************************************************************/
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, s, ans[1005][1005];

int main() {
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ans[a][b] = c;
        ans[i + 1][i + 1] = 0;  //自己到自己
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << ans[s][i];
    }
    cout << endl;

    return 0;
}
