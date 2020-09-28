/*************************************************************************
	> File Name: 拓扑序.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月22日 星期三 18时30分44秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct edg {
    int to, next;
};

edg edge[1005];
int n, m, head[1005], in_degree[1005], out_degree[1005];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].to = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }
    while(!que.empty()) {
        int temp = que.front();
        que.pop();
        cout << temp << " ";
        for (int i = head[i]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }


    return 0;
}
