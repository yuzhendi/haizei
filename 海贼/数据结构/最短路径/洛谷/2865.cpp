/*************************************************************************
	> File Name: 2865.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月01日 星期三 19时16分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int to, val, next;

};

edge edg[200005];
int n, m, edg_cnt, head[5005], ans[5005], ans2[5005], mark[5005];

void make_edge(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(ans2, 0x3F, sizeof(ans2));
    memset(head, -1, sizeof(head));

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        make_edge(a, b, c);
        make_edge(b, a, c);
    }
    queue<int> que;
    que.push(1);
    ans[1] = 0;
    mark[1] = 1;
    while(!que.empty()) {  // 从起点出发做最短路径
        int t = que.front();
        que.pop();
        mark[t] = 0;
        for (int i = head[t]; i != -1; i = edg[i].next) {
            if (ans[edg[i].to] > ans[t] + edg[i].val) {
                ans[edg[i].to] = ans[t] + edg[i].val;
            }
            if (mark[edg[i].to] == 0) {
                mark[edg[i].to] = 1;
                que.push(edg[i].to);
            }
        }
    }
    que.push(n);
    ans2[n] = 0;
    mark[n] = 1;
    while(!que.empty()) { // 从终点出发找每一个的最短路径
        int t = que.front();
        que.pop();
        mark[t] = 0;
        for (int i = head[t]; i != -1; i = edg[i].next) {
            if (ans2[edg[i].to] > ans2[t] + edg[i].val) {
                ans2[edg[i].to] = ans2[t] + edg[i].val;
            }
            if (mark[edg[i].to] == 0) {
                mark[edg[i].to] = 1;
                que.push(edg[i].to);
            }
        }
    }

    int fin = 0x3F3F3F3F;
    for (int i = 0; i < edg_cnt; i++) { // 枚举每一条边
        int t = ans[edg[i].from] + ans2[edg[i].to] + edg[i].val;
        if (fin > t && t != ans[n]) {
            fin = t;
        }
    }
    cout << fin << endl;

    return 0;
}
