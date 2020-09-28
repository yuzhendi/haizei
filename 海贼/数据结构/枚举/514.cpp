/*************************************************************************
	> File Name: 514.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月20日 星期三 19时15分09秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int ans, n;
int num[10] = {6, 2, 5, 5, 4, 5 ,6, 3, 7, 6};
int func(int x) {
    //数子x 消耗了多少火柴
    if (x == 0) return num[0];
    int sum = 0;
    while(x) {
        sum += num[x % 10];
        x /= 10;
    }
    return sum;
}


int main() {
    cin >> n;
    for (int i = 0; i < 1111; i++) {
        for (int j = 0; j < 1111; j++) {
            if (func(i) + func(j) + func(i + j) + 4 == n) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
