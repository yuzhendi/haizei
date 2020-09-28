/*************************************************************************
	> File Name: lg3366.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月08日 星期三 18时16分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std; 

struct edge {
    int from,  to;
    double val;
};
edge edg[250005];
int n, m, edg_cnt, my_union[5005]; // 维护一个并查集
double ans;
int xy[505][2];
int already = 1; // 最小生成树的节点树
bool cmp(edge a, edge b) {
    return a.val < b.val;
}

int find_root(int x) {
    if (my_union[x] != x) {
        return my_union[x] = find_root(my_union[x]);
    }
    return x;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> xy[i][0] >> xy[i][1];
        my_union[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1;j <= m; j++) {
            double x = xy[i][0] - xy[j][0];
            double y = xy[i][1] - xy[j][1];
            double t = sqrt(x * x + y * y);
            edg[edg_cnt].from  = i;
            edg[edg_cnt].to = j;
            edg[edg_cnt++].val = t;
        }
    }
    sort(edg, edg + edg_cnt, cmp);
    
    for (int i = 0; i < edg_cnt; i++) {
        int aroot = find_root(edg[i].from), broot = find_root(edg[i].to);
        if (aroot != broot) {
            // 不连同， 则将这条边加到最小生成树里
            ans = max(ans, edg[i].val);
            already++;
            my_union[aroot] = broot;
            if (already == m - n + 1) {
                break;
            }
        }
    }
    printf("%.2f\n", ans);
    return 0;
}


