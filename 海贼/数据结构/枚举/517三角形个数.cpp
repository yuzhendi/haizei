/*************************************************************************
	> File Name: 517三角形个数.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月22日 星期四 20时14分10秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n, ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n / 3; i++) {
        for (int j = i; j <= n - i; j++) {
            int t = n - i - j;
            if (t < j) break;
            if (i + j > t){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
