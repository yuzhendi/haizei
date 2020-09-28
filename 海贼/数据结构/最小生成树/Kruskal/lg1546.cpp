/*************************************************************************
	> File Name: lg3366.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月08日 星期三 18时16分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std; 

struct edge {
    int from,  to, val;
};
edge edg[200005];
int n, m, ans, my_union[5005]; // 维护一个并查集
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
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j < n; j < n; j++) {
            int val;
            cin >> val;
            edg[i].to = i * n + j + 
        }
    }
    for (int i = 1; i <= n; i++) {
        //初始化并查集
        my_union[i] = i;
    }
    sort(edg, edg + m, cmp);
    
    for (int i = 0; i < m; i++) {
        int aroot = find_root(edg[i].from), broot = find_root(edg[i].to);
        if (aroot != broot) {
            // 不连同， 则将这条边加到最小生成树里
            ans += edg[i].val;
            already++;
            if (already == n) {
                break;
            }
            my_union[aroot] = broot;
        }
    }
    if (already == n) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }
    return 0;
}


