/*************************************************************************
	> File Name: 1186.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月10日 星期三 20时31分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
struct edge {
    int to, val, next;
};

edge edg[MAX_N + 5];
int n, m, edg_cnt, head[1005], ans[1005], ans_max, que_mark[1005], from[1005];


int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[edg_cnt].to = b;
    }
    queue<int> que;
    que.push(1);
    ans[1] = 0;
    que_mark[1] = 1;
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        que_mark[t] = 0;
    }
    return 0;
}
