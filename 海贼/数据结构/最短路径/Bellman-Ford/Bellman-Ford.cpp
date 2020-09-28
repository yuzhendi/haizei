/*************************************************************************
	> File Name: Bellman-Ford.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月30日 星期二 17时34分34秒
 ************************************************************************/
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
int n, m, s, dis[MAX_N + 5][3], ans[MAX_N + 5];

int main() {
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[i][0] = a; // 起点
        dis[i][1] = b; // 终点
        dis[i][2] = c; // 权值
    }
    for (int i = 2; i <= n; i++) {  // 遍历点
        for (int j = 0; j < m; j++) { // 遍历边
            ans[dis[j][1]] = min(ans[dis[j][1]], ans[dis[j][0]] + dis[j][2]); // 直接到终点 和 先到起点 dis[j][0]+此路径长 的 最小值
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
        return 0;
}
