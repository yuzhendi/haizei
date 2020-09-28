/*************************************************************************
	> File Name: lg3366.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月08日 星期三 18时49分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int to, val, next;
};

edge edg[400005];
int n, m, edg_cnt, head[5005], ans, already;
int visit[5005]; // 判断点有没有访问过
int dis[5005]; //判断从何处来访问节点

struct node {
    int now, val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

void add_edg(int a, int b, int c) {  //链式前向星 ： 记录从点之间的关系
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(dis, 0x3F, sizeof(dis));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    while(!que.empty()) {
        node temp = que.top();
        que.pop();
        if (visit[temp.now] == 1) continue; // 已经加入到最小生成树里
        visit[temp.now] = 1;
        ans += temp.val;
        already++;
        if (n == already) break;
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            if (visit[edg[i].to] == 0 && dis[edg[i].to] > edg[i].val) {
                dis[edg[i].to] = edg[i].val;  //到达某一点的最小路径
                que.push((node){edg[i].to, edg[i].val});
            }   
    
        }
    }
    if (n == already) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }

    return 0;
}
