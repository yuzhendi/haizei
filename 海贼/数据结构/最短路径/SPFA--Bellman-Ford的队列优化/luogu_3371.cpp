/*************************************************************************
	> File Name: luogu_3371.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月01日 星期三 10时21分41秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX_N 10000
int n, m, s, cnt, ans[MAX_N + 5], head[MAX_N + 5], que_mark[MAX_N + 5];
char mark[MAX_N + 5][MAX_N + 5]; // 去重数组
struct node {
    int e, dis, next;
};
node edge[MAX_N + 5];

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b>> c;
        if (mark[a][b]) {  // 有多条路径的时候
            int ind = head[a];
            while(edge[ind].e != b) {  // 路径的终点不是b
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
        }
    }
    ans[s] = 0;
    queue<int> que;
    que.push(s);
    que_mark[s] = 1;
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        que_mark[t] = 0; // 不在队列里
        for (int i = head[t]; i != -1; i = edge[i].next) {
            if (ans[edge[i].e] > ans[t] + edge[i].dis) { // 这条边的终点的答案 大于 起点的答案 + 边的权值
                ans[edge[i].e] = ans[t] + edge[i].dis; // 以 t 作为跳板
                if (!que_mark[edge[i].e]) { // 这个点不再队列里
                    que_mark[edge[i].e]  = 1;
                    que.push(edge[i].e);
                }
            }
        }

    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            cout << " ";
        }
        if (ans[i] != 0x3F3F3F3F) {
            cout << ans[i];
        } else {
            cout << 0x7FFFFFFF;
        }
    }
    cout << endl;


    return 0;
}
