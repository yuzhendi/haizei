/*************************************************************************
	> File Name: C.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 19时23分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = n % 10, b = n% 100 / 10;
    cout << a << b << endl;
    return 0;
}
