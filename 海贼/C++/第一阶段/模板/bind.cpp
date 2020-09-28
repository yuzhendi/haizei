/*************************************************************************
	> File Name: bind.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月13日 星期四 11时18分14秒
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

int add(int a, int b) {
    cout << a << " + " << b << "=" << a + b<< endl;
    return a + b;
}
int add2(int a, int b, int c) {
    cout << a <<" + " << b  << " + " << c << " = " << a + b + c << endl;
    return a + b + c;
}

int add_cnt(function<int(int, int)> func, int &n, int a, int b) {
    n += 1;
    return func(a, b);
}

int main() {
    function<int(int)> f = bind(add, 1, placeholders::_1); // 表示输入函数的第一个参数
    function<int(int, int)> f2 = bind(add,placeholders::_2, placeholders::_1); // 占位符：表示输入函数的第n个参数
    f(1), f(2), f(3); 
    f2(1, 2), f2(2, 3);
    function<int(int, int)> f3 = bind(add2, placeholders::_2, 1, placeholders::_1);
    f3(1, 2);
    cout << "***********bind 计算函数执行次数********************************" << endl;
    int n = 0;
    function<int(int, int)> f5 = bind(add_cnt, add, ref(n), placeholders::_1, placeholders::_2); // bind是一个模板方法， 传入n的引用，要用ref, 否则T会被推导成int 类型
    f5(10, 20);
    f5(100, 200);
    function<int(int &, int ,int)> f6 = bind(add_cnt, add, placeholders::_1, placeholders::_2, placeholders::_3);
    f6(n, 1000, 2000);
    f6(n, 200, 300);
    cout << n << endl;
    return 0;
}
