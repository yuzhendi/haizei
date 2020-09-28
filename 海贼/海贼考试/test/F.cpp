/*************************************************************************
	> File Name: F.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 19时27分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 1000000
int arr[MAX_N + 5];
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ind = n >> 1;
    ind = arr[ind];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(ind - arr[i]);
    }
    cout << ans << endl;
    return 0;
}
