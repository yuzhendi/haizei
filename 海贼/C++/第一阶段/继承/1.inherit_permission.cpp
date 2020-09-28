/*************************************************************************
	> File Name: 1.inherit_permission.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月28日 星期二 18时53分28秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


class Animal {
public :
    Animal(string name, int age) : __name(name), age(age) {}
    void say() {
        cout << __name << ": Hello world!" << endl;
    }
protected:
    string __name;
private:
    int age;
};

class Cat :public Animal {
public:
    Cat() = delete; // 不允许默认构造
    Cat(string name, int age) : Animal(name, age){}
};

class Bat : protected Animal {
public:
    Bat() = delete;
    Bat(string name, int age) : Animal(name, age) {}
    void output() {
        Animal::say();
    }
};

int main() {
    Cat a("Kitty", 20);
    a.say();
    Bat b("fei", 29);
    //b.say(); // 权限受保护，类外不可访问
    b.output();
    return 0;
}
