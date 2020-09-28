/*************************************************************************
	> File Name: ../洛谷/4667.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月10日 星期三 18时52分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1100000

struct edge {
    int to, val, next;
};

struct node {
    int now, val;
    bool operator< (const node &b) const {
        return this->now > b.now;
    }
};

edge edg[MAX_N + 5];
int n, m, edge_cnt, head[260005], ans[260005];

void add_edge(int a, int b, int v) {
    edge[edge_cnt].to = b;
    edge[edge_cnt].val = val;
    head[a] = edge_cnt;
    edge_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char t;
            cin >> t;       // 抽象成点（进行 0-n 的序号排列）
            int a, b, c, d;  // a <-> b = 0; c <-> d = 1
            if (t == '/') {
                a = i * (m + 1) + j + m + 1;
                b = i * (m + 1) + j + 1;
                c = i * (m + 1) + j;
                d = i * (m + 1) + j + m + 2;
            } else {
                c = i * (m + 1) + j + m + 1;
                d = i * (m + 1) + j + 1;
                a = i * (m + 1) + j;
                b = i * (m + 1) + j + m + 2;
                
            }
            add_edge(a, b, 0);
            add_edge(b, a, 0);
            add_edge(c, d, 1);
            add_edge(d, c, 1);
        }
    }
    priority_queue<node> que;
    que,push((node){0 ,0});



    return 0;
}
