/*************************************************************************
	> File Name: Dijkstra.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月27日 星期三 19时12分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
/*迪杰斯特拉算法： 要求单一节点出发，边的权重>=0*/

struct node {
    int now, dist;//默认大顶堆, dist是起点到现在的距离
    bool operator < (const node &b) const {//重载 < ，变成小顶堆
        return this->dist > b.dist;
    }
}

int n, m, s, dis[1005][1005], ans[1005];

int main() {
    memset(dis, 0x3f, sizeof(dis));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b ,c;
        dis[a][b] = mid(dis[a][b], c);
    }
    priority_queue<node> que;
    que.push({s,0});//起点先进队
    while(!queue.empty()) {
        node t = que.pop();
        que.pop;
        if (ans[t.now] != 0x3F3F3F3F) continue;
        ans[t.now] = t.dist;
        for (int i = 1; i <= n; i++) {
            if (dis[t.now][i] != 0x3F3F3F3F) {
                que.push({i, t.dist + dis[t.now][i]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        if (ans[i] != 0x3F3F3F3F) {
            cout << 
        }
    }
    return 0;
}
