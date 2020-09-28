/*************************************************************************
	> File Name: final.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月02日 星期日 19时48分57秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class A {
public:
    virtual void say() {
        cout << "A" << endl;
    }
};

class B final: public A { // final : 不允许类再继承
public:
    void say() final override { // final ： 防止子类对相关方法的覆盖重写
        cout << "B" << endl;
    }
};

/* class C : public B {
public :
    C
    *void say() override{
        cout << "C" << endl;
    }
};*/



int main() {


    return 0;
}
