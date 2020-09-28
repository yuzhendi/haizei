/*************************************************************************
	> File Name: 拓扑序.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月22日 星期三 18时30分44秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct edg {
    int to, next;
};


edg edge[500005];
int n, m, head[5005], in_degree[5005], out_degree[5005], ans[5005];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[i].to = b;
        edge[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
        out_degree[a]++;
    }
    queue<int> que;
    for (int i  = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
            ans[i] = 1;
        }
    }
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = head[t]; i != -1; i = edge[i].next) {
            int e = edge[i].to;
            in_degree[e]--;
            ans[e] += ans[t];
            ans[e] %= 100000007;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    int f = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0) {
            f += ans[i];
            f %= 100000007;
        }
    }
    cout << f << endl;
    return 0;
}
