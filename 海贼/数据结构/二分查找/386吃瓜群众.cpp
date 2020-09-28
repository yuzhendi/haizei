/*************************************************************************
	> File Name: 386吃瓜群众.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月22日 星期二 18时39分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100005
int n, m;
struct node {
    int num, cnt;
};
node wm[MAX_N];
bool cmp(node a, node b) {
    return a.num < b.num;
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> wm[i].num;
        wm[i].cnt = i + 1;
    }
    sort(wm, wm + n, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n - 1, f = 0;
        cin >> t;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if (wm[mid].num < t) {
                l = mid + 1;
            } else if (wm[mid].num > t) {
                r = mid - 1;
            } else {
                cout << wm[mid].cnt << endl;
                f = 1;
                break;
            }
        }
        if (f == 0) cout << 0 << endl;
    }


    return 0;
}
