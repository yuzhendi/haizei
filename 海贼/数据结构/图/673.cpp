/*************************************************************************
	> File Name: 673.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月29日 星期三 20时42分50秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

struct edge{
    int to, next;
};
edge edg[100005];

int n, m, head[100005], in_degree1[100005], in_degree2[100005];


int best() {
    priority_queue<node> que;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        in_degree2[i] = in_degree1[i];
        if (in_degree2[i] == 0) {
            que.push((node){i});
        }
    }
    while(!que.empty()) {
        node t= que.top();
        que.pop();
        if (t.now > mmax) {
            ans++;
            mmax = t.now;
        }

    }
}

int worse() {
    int ans = 0, mmax = 0;
    set<node> se;
    for (int i = 1; i <= n; i++) {
        if (in_degree1[i] == 0) {
            se.insert((node){i});
        }
    }
    while(!se.empty()) {
        node temp = *se.begin();
        if (temp.now > mmax) {
            for ( set<node>::iterator item = se.begin(); item != se.end(); item++) {
                if (*item < mmax) {                   
                    temp = *item;
                    break;
                } 
            }
        }
        se.erase(temp);
        if (temp.now > mmax) {
            ans++;
            mmax = temp.now;
        }
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            int e = edg[i].next;
            in_degree1[e]--;
            if(in_degree[e] == 0) {
                se.insert((node){e});
            }
        }

    }
    return ans;
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].to = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[i]++;
    }
    int ans1 = best();
    int ans2 = worse();
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
