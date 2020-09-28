/*************************************************************************
	> File Name: 牛牛找工作.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月19日 星期三 15时56分42秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int diff, money;
};

bool cmp(node a, node b) {
    return a.diff < b.diff; //根据难度排序
}
node work[100005];
int n, m, ans[100005]; // ans记录难度对应的最大的金额
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> work[i].diff >> work[i].money;
    }
    sort(work, work + n, cmp);
    ans[0] = work[0].money;
    for (int i = 1; i < n; i++) {
        ans[i] = max(ans[i - 1], work[i].money);
    }
    for (int i = 0; i < m; i++) {
        int t, l = 0,  r = n - 1;
        cin >> t; // 工作能力
        if (t < work[0].diff) { // 一项工作都完成不了
            cout << 0 << endl;
            continue;
        }
        while(l != r) {
            int mid = (l + r + 1) >> 1;
            if (work[mid].diff <= t) { // 二分找最后一个一
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << ans[l] << endl;
    }
    return 0;
}
