/*************************************************************************
	> File Name: 395复制书稿.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月23日 星期三 19时09分07秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int ans[505][2], arr[505];
int cnt,n, m, k; // ans[cnt] 记录m - cnt - 1个人结束的编号 
int l = 1, r;

int func2(int len) {
    int sum = 0;
    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (sum + arr[i] == len) {
            sum = 0;
            cnt++;
        } else if (sum + arr[i] > len) {
            cnt++;
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
        if (sum > m) {
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
    int k = m;
    m = n;
    int sum = 0;
        ans[k][1] = m;
    int now = arr[m - 1], j = k;
    for (int i = m - 2; i >= 0; i--) {
        if (now + arr[i] > l) {
            ans[j][0] = i + 2;
            j--;
            now = arr[i];
            ans[j][1] = i + 1;
        } else if (now + arr[i] == l) {
            ans[j][0] = i + 1;
            j--;
            i--;
            now = arr[i];
            ans[j][1] = i + 1;
        } else {
            now += arr[i];
        }
    }
    ans[1][0] = 1;
    for (int i = 1; i <= k; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}
