/*************************************************************************
	> File Name: 519.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月20日 星期三 20时51分23秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

long long a, b, ans;

int main() {
    cin >> a >> b;
    for (int i = 0; i <= 9; i++) {//一堆数 9998
        for (int j = 0; j <= 9; j++) {//一个数9998 中的8 或 9
            if (i == j) continue;
            for (int k = 3; k <= 17; k++) {//长度
                 for (int l = 1; l <= k; l++) {//l 数字的位置
                    if (j == 0 && l == 1) continue;//一个数子的时和
                     if (i == 0 && l != 1) break;//一堆数是0
                     long long t = 0;
                     for (int m = 1; m <= k; m++) {
                         if (m != l) {
                             t = t * 10 + i;// 9 : 加上前面所有数
                         } else {
                             t = t * 10 + j; // 加上当前数
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
