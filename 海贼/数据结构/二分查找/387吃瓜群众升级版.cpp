/*************************************************************************
	> File Name: 387吃瓜群众升级版.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月22日 星期二 18时53分56秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
struct node {
    int num, cnt;
};

node arr[100005];

bool cmp(node a, node b) {
    return a.num < b.num;
};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].num;
        arr[i].cnt = i + 1;
    }
    sort(arr, arr + n, cmp);
    int max = arr[n - 1].num;
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n - 1;
        cin >> t;
        if (t > max) {
            cout << 0 << endl;
            continue;
        }
        while(l != r) { // <= 不幸？？？
            int mid = (l + r) >> 1;
            if (t > arr[mid].num) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        cout << arr[l].cnt << endl;
    }
    return 0;
}
