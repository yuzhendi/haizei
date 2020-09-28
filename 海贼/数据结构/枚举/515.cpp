/*************************************************************************
	> File Name: 515.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月20日 星期三 19时33分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int a, b, l, aa, bb;
double raw, now = 0x3ffffff;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> a >> b >> l;
    raw = (double) a / b;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            double temp = (double) i / j;
            if (temp >= raw && temp - raw < now - raw && gcd(i, j) == 1) {
                now = temp;
                aa = i;
                bb = j;
            }
        }
    }
    cout << aa  << " " << bb << endl;
    return 0;
}
