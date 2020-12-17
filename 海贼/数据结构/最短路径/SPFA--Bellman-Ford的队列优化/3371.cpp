/*************************************************************************
	> File Name: 3371.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月29日 星期四 18时38分13秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 500000
using namespace std;

int n, m, s, edg[MAX_N + 5][3], ans[10005]; // edg[][3]:起点 终点 距离

int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        cin >>edg[i][0] >> edg[i][1] >> edg[i][2];
    }
    ans[s] = 0; // 初始化起点
    for (int i = 1; i <= n ;i++) {
        //遍历点, 通过已经直到的点松弛一条链上的边
        for (int j = 0; j < m; j++) {
            ans[edg[j][1]] = min(ans[edg[j][1]], ans[edg[j][0]] + edg[j][2]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        if (ans[i] == 0x3f3f3f3f) cout << 0x7FFFFFFF;
        else cout << ans[i];
    }
    cout << endl;
    return 0;
}
