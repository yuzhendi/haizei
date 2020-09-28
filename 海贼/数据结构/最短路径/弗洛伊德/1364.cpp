/*************************************************************************
	> File Name: 1364.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月10日 星期三 19时40分29秒
 ************************************************************************/
/*弗洛伊德求多元最短路*/


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, ans[105][105], num[105];

int main() {
    memset(ans, 0x3F, sizeof(ans));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans[i][i] = 0;
        int a, b;
        cin >> num[i] >> a >> b;
        if (a) {
            ans[i][a] = ans[a][i] = 1;
        }
        if (b) {
            ans[i][b] = ans[b][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++)
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
        }
    }
    int mmin = 9999999;
    for (int i= 1; i <= n; i++) {
        int t = 0;
        for (int j = 1; j <= n; j++) {
            t += ans[i][j] * num[j];
        }
        mmin = min(mmin, t);
    }
    cout << mmin << endl;

    return 0;
}
