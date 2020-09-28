/*************************************************************************
	> File Name: 2865.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月01日 星期三 19时16分01秒
 ************************************************************************/
#include<iostream>
using namespace std;
#include <queue>
#include <cstring>

struct edge{
    int  to, val, next;
};

edge edg[200005];
int n, m, edg_cnt, head[5005], ans[5005], ans2[5005], mark[5005], k;
int can[100005]; // 记路连接的地方数量
void make_edge(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}
void num_place() {
    for (int i = 0; i < n; i++) {
        //int ans = 0;
        for (int t = head[i]; t != -1; t = edg[i].next) {
            can[i]++;
        }
    }
}
int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(ans2, 0x3F, sizeof(ans2));
    memset(head, -1, sizeof(head));
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a  >> b >> c;
        if (a == 1 || b == 1) {
            ans2[1] = min(ans2[1], c * 2);
        }
        make_edge(a, b, c);
        make_edge(b, a, c);
    }
    num_place();
    queue<int> que;
    que.push(1);
    ans[1] = 0;
    mark[1] = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        mark[t] = 0;
        for (int i = head[t]; i != -1 && (i == 1 || i == n || can[i] >= k); i = edg[i].next) {
            if (ans[edg[i].to] > ans[t] + edg[i].val) {
                ans2[edg[i].to] = ans[edg[i].to];
                ans[edg[i].to] = ans[t] + edg[i].val;
                if (mark[edg[i].to] == 0) {
                    mark[edg[i].to] = 1;
                    que.push(edg[i].to);
                }
            }//用ans[t]更新最短路
            if (ans[edg[i].to] < ans[t] + edg[i].val && ans2[edg[i].to] > ans[t] + edg[i].val) {
                ans2[edg[i].to] = ans[t] + edg[i].val;
                if (mark[edg[i].to] == 0) {
                    mark[edg[i].to] = 1;
                    que.push(edg[i].to);
                }
            }//用ans[t]更新次短路
            if (ans2[edg[i].to] > ans2[t] + edg[i].val) {
                ans2[edg[i].to] = ans2[t] + edg[i].val;
                if (mark[edg[i].to] == 0) {
                    mark[edg[i].to] = 1;
                    que.push(edg[i].to);
                }
            }//用ans2[t]更新最短路
        }
    }
    cout << "end" << endl;
    cout << (ans2[n] ? ans2[n] : -1) << endl;
    return 0;
}
