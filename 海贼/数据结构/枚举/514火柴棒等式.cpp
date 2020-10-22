/*************************************************************************
	> File Name: 514火柴棒等式.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月22日 星期四 19时13分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int num[13] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, ans;
int func(int x) {
    
    if (x == 0) return 6;
    int cnt = 0;
    while(x) {
        cnt += num[x % 10];
        x /= 10;
    }
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 0; i <= 1111; i++) { // 1111为最大的可能数
        for (int j = 0; j <= 1111; j++) {
            if (func(i) + func(j) + func(i + j) == n - 4) ans++;
        } 
    }
    cout << ans << endl;
    return 0;
}
