/*************************************************************************
	> File Name: right_3371.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月29日 星期四 18时56分17秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int e, dist, next;
};

edge edg[500005];
int n, m, s, ans[10005], mark[10005], head[10005];

int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >>c;
        edg[i].e = b;
        edg[i].dist = c;
        edg[i].next = head[a];
        head[a] = i;
    }
    queue<int> que;
    que.push(s);
    ans[s] = 0;
    while(!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, d = edg[i].dist;
            if (ans[e] > ans[temp] + d) { // 在这条链上距离变的点加入队列里面再次松弛
                ans[e] = ans[temp] + d;
                if (mark[e] == 0) { // 这个点没有在队列里面
                    mark[e] = 1; 
                    que.push(e);
                }
            }// 为什么这里不能break : 因为可能前面也有类似的节点距离已经改变了  
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        if (ans[i] != 0x3F3F3F3F) {
            cout << ans[i];
        } else cout << 0x7FFFFFFF;
    }
    cout << endl;

    return 0;
}
