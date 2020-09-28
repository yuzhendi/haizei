/*************************************************************************
	> File Name: visitor3.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月20日 星期四 10时47分10秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
/* 根据对象原本的类型做功能映射 */ 

class Cat;
class Mouse;
class Dog;
class Bat;
class Animal {
public:
    // 增加一个接口类
    class IVisitor {
    public:
        virtual void visit(Cat *) = 0;
        virtual void visit(Dog *) = 0;
        virtual void visit(Mouse *) = 0;
        virtual void visit(Bat *) = 0;
    }; 
    // 基类 提供一个纯虚方法
    virtual void Accept(IVisitor *vis) = 0;
    virtual ~Animal(){}
};

class Cat : public Animal{
public :
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }

};

class Dog : public Animal{
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }

};

class Mouse : public Animal{
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
    
};
class Bat : public Animal {
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class AnimalCout : public Animal::IVisitor { // 定义一个功能类
public:
    virtual void visit(Cat *obj) {
        cout << "this is a Cat" << endl;
    }
    virtual void visit(Dog *obj) {
        cout << "this is a Dog" << endl;
    }
    virtual void visit(Mouse *obj) {
        cout << "this is a Mouse" << endl;
    }
    virtual void visit(Bat *obj) {
        cout << "this is a Bat" << endl;
    }
};
 
class Cnt_class : public Animal::IVisitor {
private:
    int cnt, cnt1, cnt2, cnt3, cnt4;
public:
    Cnt_class():cnt(0), cnt1(0), cnt2(0), cnt3(0), cnt4(0) {}
    virtual void visit(Cat *obj) {this->cnt++; this->cnt1++;}
    virtual void visit(Dog *obj) {this->cnt++; this->cnt2++;}
    virtual void visit(Bat *obj) {this->cnt++; this->cnt3++;}
    virtual void visit(Mouse *obj) {this->cnt++; this->cnt4++;}
    int get_Cnt() {
        return this->cnt;
    }
};


int main() {
    srand(time(0));
    Animal *arr[10];
    for (int i = 0; i < 10; i++) {
        switch(rand() % 4) {
            case 0: arr[i] = new Cat(); break;
            case 1: arr[i] = new Dog(); break;
            case 2: arr[i] = new Mouse(); break;
            case 3: arr[i] = new Bat(); break;
        }
    }
    /*for (int i = 0; i < 10; i++) {
        if (dynamic_cast<Cat *>(arr[i])) {
            cout << "this is a cat" << endl;
        } else if (dynamic_cast<Dog *>(arr[i])){
            cout << "this is a dog" << endl;
        } else if (dynamic_cast<Mouse *>(arr[i])){
            cout << "this is a mouse" << endl;
        } else { // 每次增加新的类时， 都要添加一个if 判断,不增加判断的时候编译可以通过，运行期才能看见 种类多的时候， 就严重影响效率
            cout << "change pointer error!" << endl;
        } 
    }*/
    AnimalCout vis;
    Cnt_class cnt;
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
        arr[i]->Accept(&cnt);
    }
    int sum = cnt.get_Cnt();
    cout << "sum of class is " << sum << endl;
    return 0;
}
