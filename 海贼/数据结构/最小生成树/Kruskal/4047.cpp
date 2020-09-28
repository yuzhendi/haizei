/*************************************************************************
	> File Name: 4047.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月15日 星期三 20时01分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int n, k, xy[1005][2], my_union[1005], already = 1;
struct edge {
    int from, to;
    double val;
};
edge edg[500005];
int edg_cnt;

bool cmp(edge a, edge b) {
    return a.val < b.val;
}
int find_fa(int x) {
    if (my_union[x] != x) {
        return my_union[x] = find_fa(my_union[x]);
    }
    return x;
}
int main() {
    cin >> n >>k ;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
        my_union[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = xy[i][0] - xy[j][0];
            int y = xy[i][1] - xy[j][1];
            edg[edg_cnt].from = i;
            edg[edg_cnt].to = j;
            edg[edg_cnt].val = sqrt(x * x + y * y);
            edg_cnt++;
        }
    }
    sort(edg, edg + edg_cnt, cmp);
    int flag = 0;
    for (int i = 0; i < edg_cnt; i++) {
        int fa = find_fa(edg[i].from), fb = find_fa(edg[i].to);
        if (fa != fb) {
            if (flag == 1) {
                printf("%.2lf\n",edg[i].val);
                return 0;
            }
            my_union[fa] = fb;
            already++;
            if (already == n - k + 1) {
                flag = 1;
            }
        }
    }
    return 0;
}
