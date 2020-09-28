/*************************************************************************
	> File Name: 395复制书稿.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月23日 星期三 19时09分07秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int ans[505], arr[505];
int cnt,n, m, k; // ans[cnt] 记录m - cnt - 1个人结束的编号 
int l = 1, r;

int func2(int len) {
    int sum = 0;
    cnt = 0;
    ans[0] = n;
    for (int i = n - 1; i >= 0; i--) {
        if (sum + arr[i] == len) {
            ans[++cnt] = i;
            sum = 0;
        } else if (sum + arr[i] > len) {
            ans[++cnt] = i + 1;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }
    if (sum != 0)cnt++;
    return cnt;
}

int func() {
    while(l != r) {
        int mid = ( l + r) >> 1;
        int sum = func2(mid);
        if (sum >= m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        r += arr[i];
    }
    func();
    ans[0] = n;
    int start = 1;
    for (int i = cnt - 1; i >= 0; i--) {
        cout << start << " " << ans[i] << endl;
        start = ans[i] + 1;
    }
    return 0;
}
