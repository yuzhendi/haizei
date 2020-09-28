/*************************************************************************
	> File Name: 1.virtual.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月01日 星期六 15时51分25秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class Animal {
public:
    virtual void run() { // 加入virtual可以是的函数跟着对象走
        cout << "Animal " << endl;
    }
};

class Cat : public Animal{
public:
    void run() override{ // override 不影响功能的实现， 可以将潜在bug显示 判断子类和父类的虚函数一致
        cout << "cat" << endl;
    }
};

int main() {
    Cat a;
    Animal &b = a;
    Animal *c = &a;
    a.run(); // 普通的成员方法是依赖于类走的 cat
    b.run(); // Animal
    c->run(); // Animal


    return 0;
}
