/*************************************************************************
	> File Name: D.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 19时11分52秒
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

#define s 1e-5
double func(double x) { return x * exp(x);}
double a;
int main() {
    cin >> a;
    double l = 0, r = a;
    double x = (l + r) / 2.0;
    while(fabs(func(x) - a) >=  s) {
        //cout << fabs(func(x) - a) << endl;
        if (a - func(x) > 0) {
            l = x;
        } else {
            r = x;
        }
        x = (l + r) / 2.0;

    }
    printf("%.4lf\n", x);
    return 0;
}
