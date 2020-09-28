/*************************************************************************
	> File Name: 3393.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月01日 星期三 18时30分13秒
 ************************************************************************/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

//边信息
struct edge{
    int to, next;
};
//地杰斯特拉结点
struct node {
    int now, val;
    bool operator< (const node & b) const {
        return this->val > b.val;
    }
};

//广搜结点
struct sta {
    int now, left;//在哪个点，还应搜多远
};

edge edg[400005];//边信息
long long n, m, k, s, p, q, head[100005], edg_cnt, ans[100005], zombie[100005];
//
char status[100005];//状态max-zombie 1-danger 0-normal

void make_edge(int a, int b) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt;
    edg_cnt++;
}
void init_status() {
    queue<sta> que;
    for(int i = 0;  i < k; i++) {
        que.push((sta){zombie[i], s});
        status[zombie[i]] = 0x3F;
    }
    while(!que.empty()) {
        sta temp = que.front();
        que.pop();
        if(temp.left == 0) {
            continue;
        }
        for(int i = head[temp.now]; i != -1; i = edg[i].next){
            if(status[edg[i].to] == 0) {
                status[edg[i].to] = 1;
                que.push((sta){edg[i].to, temp.left - 1});
            }
        }
    }
}

long long dist(int x) {
    if(status[x] == 0) {
        return p;
    } else if (status[x] == 1) {
        return q;
    }
    return 0x3F3F3F3F3F3F3F3F;
}

void dijkstra() {
    priority_queue<node> que;
    que.push((node){1, 0});
    ans[1] = 0;
    while(!que.empty()) {
        node temp = que.top();
        que.pop();
        if(temp.val > ans[temp.now]) {
            continue;
        }
        for(int i = head[temp.now]; i != -1; i = edg[i].next) {
            if (ans[edg[i].to] > ans[temp.now] + dist(edg[i].to)) {
                ans[edg[i].to] = ans[temp.now] + dist(edg[i].to);
                que.push((node){edg[i].to, ans[edg[i].to]});
            }
        }

    }
}

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3F, sizeof(ans));

    cin >> n >> m >> k >> s >> p >> q;
    for(int i = 0; i < k; i++ ){
        cin >> zombie[i];
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        make_edge(a,b);
        make_edge(b, a);
    }
    init_status();
    dijkstra();
    cout << ans[n] - dist(n) << endl;

    return 0;
}
