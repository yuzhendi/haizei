/*************************************************************************
	> File Name: 390原木切割.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月22日 星期二 19时12分52秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[100005];
bool cmp(int a, int b) {
    return a < b;
}
bool func(int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (arr[i] / x);
    }
    if (cnt >= m) return true;
    return false;
}

int main() {
    cin >> n >> m;
    int r = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        r = max(r, arr[i]);
    }
    sort(arr, arr + n, cmp);
    int l = 1;
    while(l != r) {
        int mid = (l + r + 1) >> 1;
        if (func(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        } 
    }
        cout << l << endl;
    return 0;
}
