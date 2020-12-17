/*************************************************************************
	> File Name: 519优雅数.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月22日 星期四 20时34分21秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a, b, ans;
    cin >> a >> b;
    for(int i = 0; i < 10; i++) {// i 表示多的那个数字
        for (int j = 0; j < 10; j++) { // j 表示只有1个的数字
            if (i == j) continue;
            for (int k = 3; k <= 17; k++) { // k 表示优雅数的长度
                for (int l = 1; l <= k; l++) { // l 表示独立数字所在的位置
                    if (i == 0 && l != 1) break; // 有前导0
                    if (j == 0 && l == 1) continue;
                    long long t = 0;
                    for (int m = 1; m <= k; m++) { // 枚举长度为k的优雅数
                        if (m == l) {
                            t = t * 10 + j;
                        } else {
                            t = t * 10 + i;
                        }
                    }
                    if (t >= a && t <= b) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
