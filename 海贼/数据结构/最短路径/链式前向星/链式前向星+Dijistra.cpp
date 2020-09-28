/*************************************************************************
	> File Name: 链式前向星+Dijistra.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月30日 星期二 17时10分56秒
 ************************************************************************/

// 洛谷4479
//  不能有路径为负值的边
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 100000


struct node {
    int e, dis, next;
};

struct point {
    int now, dist;
    bool operator< (const point &b) const {
        return this->dist > b.dist;
    }
};

int n, m, s, ans[MAX_N + 5], head[MAX_N + 5];  
node edge[MAX_N * 2 + 5];

int main() {
    memset(head, 0x3F, sizeof(head));
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s; // s 是起点
    for (int i = 0; i < m; i++) { // 输入边的信息
        int a, b, c;
        edge[i].e = b; // 终点
        edge[i].dis = c;
        edge[i].next = head[a];
        head[a] = i;

    }
    priority_queue<point> que;  // 优先队列
    while(!que.empty()) {
        point t = que.top();
        que.pop();
        if (ans[t.now] != 0x3F3F3F3F) continue; // 已经遍历过
        ans[t.now] = t.dist;
        for (int i = head[t.now]; i != -1; i = edge[i].next) {  // 以 head[t.now]为起点的所有路径入队
           if (ans[edge[i].e == 0x3F3F3F3F])
                 que.push({edge[i].e, t.dist + edge[i].dis}); // 终点是edge[i].e， 权值是 t.dist + edge[i].dis 的路径入队
        }
    }
    for (int i = 1; i <= n ; i++) {
        if (i != 1) cout << " ";
        cout << ans[i];
    }
    return 0;
}
