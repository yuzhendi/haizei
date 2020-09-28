/*************************************************************************
	> File Name: FPFA
    >> Author: yuzhendi
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月03日 星期三 18时53分31秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_N 10000
#define MAX_M 50000


int n, m, s,cnt, ans[MAX_N + 5], head[MAX_N + 5],que_mark[MAX_N + 5];

struct node {
    int e, dis, next;
};
node edge[MAX_M + 5];
char mark[MAX_N + 5][MAX_N + 5];

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (mark[a][b]) {
        int ind = head[a];
        while (edge[ind].e != b) {
            ind = edge[ind].next;
        }
        edge[ind].dis = min(c, edge[ind].dis);
    } else {
        mark[a][b] = 1;
        edge[cnt].e = b;
        edge[cnt].dis = c;
        edge[cnt].next = head[a];
        head[a] = cnt;
        cnt++;
    }}
    ans[s] =  0;
    queue<int> que;
    que.push(s);
    que_mark[s] = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        que_mark[t] = 0;
        for (int i = head[t]; i != -1; i = edge[i].next) {
            if (ans[edge[i].e] > ans[t] + edge[i].dis) {
                ans[edge[i].e] = ans[t] + edge[i].dis;
                if (!que_mark[edge[i].e]) {
                    que_mark[edge[i].e] = 1;
                    que.push(edge[i].e);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i - 1) {
            cout << " ";
        }
        if (ans[i] != 0x3F3F3F3F) {
            cout << ans[i];
        } else {
            cout << 0x7FFFFFFF ;
        }
    }
    return 0;
}
