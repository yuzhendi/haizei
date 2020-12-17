/*************************************************************************
	> File Name: 1144.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月01日 星期三 16时46分23秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX_N 1000000
#define MOD 100003
using namespace std;

struct edge {
    int e ,next;
};

struct node {
    int now, dist;
    bool operator< (const node &b) const {
        return this->dist > b.dist;
    }
};

edge edg[4000005];
int n, m, mcnt = 1, head[MAX_N + 5], ans[MAX_N + 5], cnt[MAX_N + 5]; 
void add(int x, int y) {
    edg[mcnt].e = y;
    edg[mcnt].next = head[x];
    head[x] = mcnt;
    mcnt++; // 边的序号
}
int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    ans[1] = 0; // 起点
    cnt[1] = 1;
    while(!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.dist > ans[temp.now]) continue;
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            int e = edg[i].e;
            if (ans[e] > ans[temp.now] + 1) {
                ans[e] = ans[temp.now] + 1;
                cnt[e] = cnt[temp.now];
                que.push((node){e, ans[e]});
            } else if (ans[e] == ans[temp.now] + 1) {
                cnt[e] += cnt[temp.now];
                cnt[e] %= MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << endl;
    }
    return 0;
}
