/*************************************************************************
	> File Name: 5.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月21日 星期二 21时05分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

int main() {
    int n, arr[MAX_N + 5];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    nth_element(arr, arr + (n / 2), arr + n);
    int mid = arr[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(mid - arr[i]);
    }
    cout << ans << endl;
    return 0;
}
