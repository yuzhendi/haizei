/*************************************************************************
	> File Name: constexpre.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月02日 星期日 18时56分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

constexpr int f(int x) {
    return x * x + 1;
}
class A {
public :
    constexpr A(int x, int y) : x(x), y(y){}
    int x, y;
};

int main() {
    //const int n = 123;
    int n;
    cin >> n;
    const int m = n * 2; // const 是运行期常量
    cout << n << endl;
    cout << f(2) << endl;
    constexpr int a = f(3);
    cout << a << endl;
    constexpr A _a(2, 3);
    return 0;
}
