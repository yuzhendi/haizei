/*************************************************************************
	> File Name: 1629_2.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月29日 星期四 19时44分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int e, dist, next;
};

struct node {
    int now, dist;
    bool operator< (const node &b) const {
        return this->dist > b.dist;
    }
};

int n, m, head[2][10005], ans[2][1005];
edge edg[2][100005];

void func(int x) {
    priority_queue<node> que;
    que.push((node{1, 0}));
    while(!que.empty()) {
        node temp = que.top();
        que.pop();
        if (ans[x][temp.now] <= temp.dist) {
            continue;
        }
        ans[x][temp.now] = temp.dist;
        for (int i = head[x][temp.now]; i != -1; i = edg[x][i].next) {
            int e = edg[x][i].e, d = edg[x][i].dist;
            if (ans[x][e] > ans[x][temp.now] + d) {
                que.push((node{e, ans[x][temp.now] + d}));
            }
        }
    }
}


int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[0][i].e = b;
        edg[0][i].dist = c;
        edg[0][i].next = head[0][a];
        head[0][a] = i;
        edg[1][i].e = a;
        edg[1][i].dist = c;
        edg[1][i].next = head[1][b];
        head[1][b] = i;
    }
    func(0);
    func(1);
    int ret = 0;
    for (int i = 2; i <= n; i++) {
        ret += ans[0][i] + ans[1][i];
    }
    cout<< ret << endl;
    return 0;
}
