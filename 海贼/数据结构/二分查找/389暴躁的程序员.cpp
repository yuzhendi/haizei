/*************************************************************************
	> File Name: 389暴躁的程序员.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月22日 星期二 19时34分18秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[100005];

int func2(int x) {
    int s = 1, last = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - last >= x) {
            s++;
            last = arr[i];
        }
    }
    return s;
}

int func() {
    int l = 1, r = arr[n - 1] - arr[0];
    while(l != r) {
        int mid = (l + r + 1) >> 1;
        int s = func2(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << func() << endl;

    return 0;
}

