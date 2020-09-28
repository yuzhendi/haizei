/*************************************************************************
	> File Name: 被3整除.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月19日 星期三 16时11分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

// 找规律， 余数的规律, 可以尝试数学归纳法证明
// 每三个有两个 即： 1 0 0   1 0 0  1 0 0
int main() {
    long long l, r;
    cin >> l >> r;
    int a = l / 3 * 2 + l % 3 - 1;
    int b = r / 3 * 2 + r % 3 - 1;
    cout << b - a + 1<< endl;
    return 0;
}
