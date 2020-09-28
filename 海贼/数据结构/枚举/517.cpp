/*************************************************************************
	> File Name: 517.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月20日 星期三 19时49分09秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n / 3; i++) {// i < j不需要去重 
        for (int j = i; j <= (n - i) >> 1; j++) {
            int k = n - i - j;
            if (i + j > k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
