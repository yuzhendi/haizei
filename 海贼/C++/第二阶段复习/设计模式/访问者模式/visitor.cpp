/*************************************************************************
	> File Name: visitor.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月06日 星期日 22时17分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class A{
public:
    virtual ~A(){}
};

class B : public A{};
class C : public A{};
class D : public A{};
/* 当创建新的类E时，没有条件分支，运行时会报错，所以需要访问者模式*/
int main() {
    A *arr[10];
    for (int i = 0; i < 10; i++) {
        switch(rand() % 3) {
            case 0: arr[i] = new B(); break;
            case 1: arr[i] = new C(); break;
            case 2: arr[i] = new D(); break;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (dynamic_cast<B *>(arr[i])) { // 通过虚函数表地址来判断是否是B类（指针的强制转换，要求必须是虚函数）
            cout << "this is B class" << endl;
        } else if (dynamic_cast<C *>(arr[i])) {
            cout << "this is C class" << endl;
        } else if (dynamic_cast<D *> (arr[i])) {
            cout << "this is D class" << endl;
        } else {
            cout << "error!" << endl;
        }
    }

    return 0;
}
