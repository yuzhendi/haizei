/*************************************************************************
	> File Name: 4826.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月15日 星期三 20时32分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
    int from, to ;
    long long val;
};
edge edg[2000005];
long long n, edg_cnt, num[2005], my_union[999999];

bool cmp(edge a, edge b) {
    return a.val > b.val;
}
long long find_fa(int x) {
    if (x != my_union[x]) {
        return my_union[x] = find_fa(my_union[x]);
    }
    return x;
}
long long already = 1, ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        my_union[i] = i;
    }
    for (int i = n + 1; i <= 99999; i++) {
        my_union[i] = i;
    }
    for (int i =1; i <= n; i++) { //处理边的信息
        for (int j = i + 1; j <= n; j++) {
            edg[edg_cnt].from = i;
            edg[edg_cnt].to = j;
            edg[edg_cnt].val = (num[i] ^ num[j]);
            edg_cnt++;
        }
    }
    sort(edg, edg + edg_cnt, cmp);
    for (int i = 0; i < edg_cnt; i++) {
        long long fa = find_fa(edg[i].from), fb = find_fa(edg[i].to);
        if (fa != fb) {
            my_union[fa] = fb;
            already++;
            ans += edg[i].val;
            if (already == n) break;
        }
    }
    cout << ans  << endl;
    return 0;
}
