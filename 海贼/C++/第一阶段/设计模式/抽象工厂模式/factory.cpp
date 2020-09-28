/*************************************************************************
	> File Name: factory.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月18日 星期二 18时02分37秒
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;
// 当成员属性比较多的时候, 将建立对象的方法交给工厂， 外部不能直接建立对象

class ICar {
public:
    class IFactory {
    public:
        virtual ICar* create() = 0; // 用来创建一个新的对象
    };
    virtual void run() = 0;

protected:
    ICar(){}
    ~ICar(){}
    
};

class BenzCar : public ICar {
    BenzCar(){}
public:
    class Factory : public ICar::IFactory {
        virtual ICar* create() {
            return new BenzCar();
        }
    };
    virtual void run() {
        cout << "this is BenzCar running..." << endl;
    }

};
class BmwCar : public ICar {
    BmwCar(){}
    public:
    class Factory : public ICar::IFactory {
        virtual ICar* create() {
            return new BmwCar();
        }
    };
    virtual void run() {
        cout << "this is BmwCar running..." << endl;
    }
};
class AudiCar : public ICar {
    AudiCar(){}
    public:
    class Factory : public ICar::IFactory {
        virtual ICar* create() {
            return new AudiCar();
        }
    };
    virtual void run() {
        cout << "this is AudiCar running..." << endl;
    }

};

ICar::IFactory* fac[3] = {new BenzCar::Factory(), new AudiCar::Factory(), new BmwCar::Factory()}; // 创建三个工厂用来建立对象

ICar *cars[10]; // 要创建的10个对象

int main() {
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        cars[i] = fac[rand() % 3]->create(); 
        cars[i]->run();
    }


    return 0;
}
