/*************************************************************************
	> File Name: 1340.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月15日 星期三 18时55分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
struct edge {
    int from, to, val, mtime;
};
edge edg[6005];
int n, m, my_union[205];

int find_fa(int x) {
    if (my_union[x] != x) {
        
        return my_union[x] = find_fa(my_union[x]);
    }
    return x;
}

bool cmp(edge a, edge b) {
    return a.val < b.val;
}
void init_union() {
    for (int i = 0; i <= n; i++) {
        my_union[i] = i;
    }
}

int main() {
    cin >> n>> m;
    for (int i = 0; i < m; i++) {
        cin >> edg[i].from >> edg[i].to >> edg[i].val;
        edg[i].mtime = i;
    }
    sort(edg, edg + m, cmp);
    for (int i = 0; i < m; i++) {
        int ans = 0, already = 1;
        init_union();
        for (int j = 0;j < m; j++) { //遍历所有边
            if (edg[j].mtime <= i) {
                int fa = find_fa(edg[j].from), fb = find_fa(edg[j].to) ;
                if (fa != fb ) {
                    my_union[fa] = fb;
                    ans += edg[j].val;
                    already++;
                    if (already == n) break;
                
                }
            }
        }
        if (already == n) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
