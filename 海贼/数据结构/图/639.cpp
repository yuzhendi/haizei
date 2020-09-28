/*************************************************************************
	> File Name: 639.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月29日 星期三 19时56分51秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct edge{
    int to, next;
};
edge[1000005];

int n, m, edg_cnt, head[1005], in_degree[1005], ;

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t;

    }
    queue<int> que;
    for (int i  =1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
            ans[i] = 1;
        }
    }
    int end = 0;
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            ans[e] = max(ans[e], ans[t] + 1);
            in_degree[e]--;
            if(in_degree[e] == 0) {
                que.push(e);
            }
        }
        end = max(end, ans[t]); // 最长的一条边的链
    }
    cout << end << endl;
    return 0;
}
