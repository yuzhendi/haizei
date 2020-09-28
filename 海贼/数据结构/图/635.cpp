/*************************************************************************
	> File Name: 635.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月22日 星期三 19时43分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n, m, head[105], in_degree[105], out_degree[105], c[105], u[105];

struct edge {
    int to, next, val;
};
edge edg[10005];
int main() {
    cin >> n >> m;
    queue<int> que;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
        if (c[i] != 0) {
            que.push(i); // 起点
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i].to = b;
        edg[i].val = c;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
        out_degree[a]++;
    }
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to, v = edg[i].val;
            if (c[t]> 0)  c[e] += v * c[t];
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
                c[e] -= u[e];
            }
        }
    }
    int f= 0 ;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0 && c[i]> 0) {
            cout << i << " " << c[i] << endl;
            f = 1;
        }
    }
    if (f == 0) cout << "NULL" << endl;
    return 0;
}
