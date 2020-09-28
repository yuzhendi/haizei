/*************************************************************************
	> File Name: 1629.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月01日 星期三 15时41分14秒
 ************************************************************************/

/*思路：
 *  正着来一遍Dijstra算法， 然后将路径反着来一边（解决单向问题)
 *  */

#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
    int to, val, next; 
};

struct node {
    int now, val;
    bool operator< (const node &b) const  {
        return this->val > b.val;
    }
};

int n, m, head1[1005], head2[1005], ans1[1005], ans2[1005];
edge dege1[100005], edge2[100005];
int main() {
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    memset(ans1, 0x3F, sizeof(ans1));
    memset(ans2, 0x3F, sizeof(ans2));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg1[i].to = b;
        edg1[i].val = c;
        edg1[i].next = head1[a];
        head1[a] = i;
        edg2[i].to = a;
        edg2[i].val = c;
        edg2[i].next = head2[b];
        head2[b] = i;
    }
    priority_queue<node> que;
    que.push({1, 0});
    ans1[1] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.val > ans1[temp.now]) {
            continue;
        }
        for (int cnt = head1[temp.now]; cnt != -1; cnt = edg1[cnt].next) {
            if (ans1[edg1[cnt].to] > temp.val + edg1[cnt].val) {
                ans1[edg1[cnt].to] = temp.val + edg1[cnt].val;
                que.push({edg1[cnt].to, ans1[edg1[cnt].to]});
            }
        }
    }
    que.push({1, 0});
    ans2[1] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.val > ans2[temp.now]) {
            continue;
        }
        for (int cnt = head2[temp.now]; cnt != -1; cnt = edg2[cnt].next) {
            if (ans2[edg2[cnt].to] > temp.val + edg2[cnt].val) {
                ans2[edg2[cnt].to] = temp.val + edg2[cnt].val;
                que.push({edg2[cnt].to, ans2[edg2[cnt].to]});
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += ans1[i] + ans2[i];
    }
    cout << ans << endl;
    return 0;
}
