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

struct my_int {
    int num;
    bool operator<(const my_int &b) const {
        return this->num > b.num;
    }
};

edg edge[400005];
int n, m, head[2005], in_degree[2005], out_degree[2005];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    int star = 99999;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[i].to = b;
        edge[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }
    priority_queue<my_int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push((my_int){i});
        }
    }
    int f = 0;
    while(!que.empty()) {
        int temp = que.top().num;
        que.pop();
        if (f == 1) cout << " ";
        f = 1;
        cout << temp;
        for (int i = head[temp]; i != -1; i = edge[i].next) {
            int e = edge[i].to;
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push((my_int){e});
            }
        }
    }
    cout << endl;

    return 0;
}
