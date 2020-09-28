/*************************************************************************
	> File Name: 链式前向星.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月27日 星期三 19时49分10秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct node {
    int end, dis, pre;
};

struct point {
    int now, dist;
    bool operator < (const point &b)const {
        return this->dist > b.dist;
    }
};

int n, m, s,  ans[100005], head[100005];
node edge[200005];


int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b ,c;
        cin >> a >> b >> c;
        edge[i].end = b;//终点
        edge[i].dis = c;
        edge[i].pre = head[a];
        head[a] = i;
    }
    priority_queue<point> que;
    que.push({s, 0});//起点
    while(!que.empty()) {
        point t = que.top();
        que.pop();
        if (ans[t.now] != 0x3F3F3F3F) continue;
        ans[t.now] = t.dist;
        for (int i = head[t.now]; i != -1 ; i = edge[i].pre)//只找以head[i]为起点的路径
        if (ans[edge[i].end] == 0x3F3F3F3F)//没有遍历过
            que.push({edge[i].end, t.dist + edge[i].dis});
    }
    for (int i = 1; i<= n; i++ ) {
        if (i != 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}


