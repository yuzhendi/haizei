/*************************************************************************
	> File Name: 1.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月15日 星期六 20时50分44秒
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

int a = 0;

int main() {
    function<double(double)> inc = [](int x){return 1 + x;};
    int (*square)(int) = [](int x){return x  * x;};
    cout << a << endl;
    return 0;
}
