/*************************************************************************
	> File Name: 498.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月24日 星期四 10时44分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int ans[35], n;
    ans[0] = 1;
    ans[1] = 2;
    cin >> n;
    for (int i = 2; i < n; i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    cout << ans[n - 1] << endl;

    return 0;
}
