/*************************************************************************
	> File Name: 1.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月02日 星期日 20时24分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define TEST(a, f) {\
    cout << #a << " : " << #f << " ";\
    f(a);\
}

void f2(int &x) {
    cout << "left val" << endl << endl;
}
void f2(int &&x) {
    cout << "right val" << endl << endl;
}

void f(int &x) {
    cout << "left val" << endl;
    TEST(x, f2);
}
void f(int &&x) {
    cout << "right val" << endl;
    TEST(forward<int &&>(x), f2); // forward: 用右值引用的方式向下传递     move(x): 强制转换成右值
}

int func_test(const int &x) { // 加入const 可以传入右值调用左值引用
    //x += 1;
    cout << x << endl;
    return x;
}
/*int func_test(const int &&x) { // 左值无法绑定在右值引用上
    //x += 1;
    cout << x << endl;
    return x;
}*/
int main() {
    int a, b = 1, c = 3;
    (++a) = b + c;
    cout << a << endl;
    (a++);
    (a = b) = c;
    cout << a << " " << b << endl;
    int arr[10];
    arr[3] = 12;
    (a += 3) = 67;
    cout << a << endl;
    TEST(a += 3, f);
    TEST(1 + 4, f);
    TEST(b + c, f);
    TEST(a++, f);
    TEST(++a, f);
    cout << a << endl;
    func_test(a); // 左值无法绑定再右值引用上, 右值要自动销毁的
    cout << a << endl;
    return 0;
}
