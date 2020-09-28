/*************************************************************************
	> File Name: 499.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月24日 星期四 11时20分28秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double v1, v2, s, x, ans;
    cin >> s >> v1 >> v2;
    x = (v1 + v2) * s / (3 * v1 + v2);
    ans = x / v2 + (s - x) / v1;
    printf("%.2f\n", ans);

    return 0;
}
