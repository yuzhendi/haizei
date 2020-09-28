/*************************************************************************
	> File Name: 1642.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月01日 星期三 20时33分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define MAX_N 100000

using namespace std;
struct edge {
    int to, val, next;
};

struct node {
    int now, val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

int n, m, b, edg_cnt, cost[10005], head[MAX_N + 5], ans[MAX_N + 5];
edge edg[MAX_N + 5];
void make_edge(int a, int b, int c) {
    edg[edg_cnt].val = c;
    edg[edg_cnt].to = b;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int dijistra(int mmax) {
    memset(ans, 0x3F, sizeof(ans));
    priority_queue<node> que;
    que.push((node{1, 0}));
    ans[1] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.val > ans[temp.now]) {
            continue;
        }
        for (int i = head[temp.now] ; i != -1; i = edg[i].next) {
            int to = edg[i].to, va = edg[i].val;
            if (cost[to] <= mmax && ans[to] > temp.val + va) { // 花费的钱更少且血量可以通过
                ans[to] = temp.val + va;
                que.push((node){to, ans[to]});
            }
        }
    }
    if (ans[n] >= b || ans[n] == 0x3F3F3F3F) {  // 消耗的血量大于 b
        return 0;
    } else {
        return 1;
    }
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];  // 输入对应要花费的金币
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        make_edge(a, b, c);
        make_edge(b, a, c);

    }
    int l = 0, r = 1000000000;
    while (l != r) { // 最大最下  ： 二分答案    0000011111
        int mid = (l + r) >> 1;
        if (dijistra(mid)) {
            r = mid;
        } else {
            l = mid + 1;
           }

    }
    if (l == 1000000000) {  // 不管有多少钱都到不了
        cout << "AFK" << endl;
    } else {
        cout << l << endl;
    }
    return 0;
}
