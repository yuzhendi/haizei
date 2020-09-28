/*************************************************************************
	> File Name: Dijkstra.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月12日 星期五 20时12分56秒
 ************************************************************************/

//  单元最短路径

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct node {
    int now, dist; // now:目前的位置， dist：距离
    bool operator<(const node &b) const {
        return this->dist > b.dist;
    } // 重载小于号： 默认大顶堆,反者写
};

int n, m, s, dis[1005][1005], ans[1005];

int main() {
    cin >> n >> m >> s;
    memset(dis, 0x3F, sizeof(dis));
    memset(ans, 0x3F, sizeof(ans));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = c;
    }
    priority_queue<node> que; // 优先队列
    que.push({s, 0});
    while(!que.empty()) {
        node t = que.top();
        que.pop();
        if (ans[t.now] != 0x3F3F3F3F) continue;
        ans[t.now] = t.dist;
        for (int i = 1; i <= n; i++) {
            if (dis[t.now][i]) {
                que.push({i, t.dist + dis[t.now][i]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        if (ans[i] != 0x3F3F3F3F) {
            cout << ans[i];
        } else {
            cout << 0x3F3F3F3F;
        }
    }
    cout << endl;
    return 0;
}
