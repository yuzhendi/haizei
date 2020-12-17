/*************************************************************************
	> File Name: factory.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月07日 星期一 22时24分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

/* 说明： Car的工厂类 
 * 当Car的属性比较多的时候，生成对象就很麻烦,要初始化很多属性
 * 只有工厂可以创建对象, 构造函数和拷贝函数设置成受保护的(私有的，设置子类的就不能构造)
*/
class ICar{
public:
    
    class IFactory { // 工厂类设置在类里面表示车类的工厂
    public:
        virtual ICar *create() = 0;
    };
    
    virtual void run() = 0; // 纯虚函数
protected:
    ICar(){}
    ~ICar(){}
};


class BenzCar : public ICar { // 子类的构造函数设置为私有的，外部不能再创建对象
    BenzCar(){}
public:
    class Factory : public ICar::IFactory {
    public:
        virtual ICar *create() { // 子类自己的专门的工厂
            return new BenzCar();
        }
    };

    virtual void run() {
        cout << "BenzCar run" << endl;
    }
};

class BmwCar : public ICar {
    BmwCar(){}
public:
    class Factory : public ICar::IFactory {
    public:
        virtual ICar *create() { // 子类自己的专门的工厂
            return new BmwCar();
        }
    };

    virtual void run() {
        cout << "BmwCar run" << endl;
    }
};
//初始化两个工厂
ICar::IFactory *fac[2] = {new BenzCar::Factory(), new BmwCar::Factory()};

int main() {
    srand(time(0));
    ICar *cars[10];
    for (int i = 0; i < 10; i++) {
        cars[i] = fac[(rand() % 2)]->create();
    }

    for (int i = 0; i < 10; i++) {
        cars[i]->run();
    }

    return 0;
}
