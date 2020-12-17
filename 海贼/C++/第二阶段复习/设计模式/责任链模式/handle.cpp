/*************************************************************************
	> File Name: handle.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月07日 星期一 23时05分12秒
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

class ICar {
public :
    class IFactory {
    public :
        virtual ICar *crearte() = 0;
    };
    class IHandler {
    public :
        IHandler() : next(nullptr) {}
        virtual bool is_valid(int x) = 0;
        virtual ICar *do_it() = 0;
        virtual void test() = 0;
        IHandler *next;
    };
    virtual void run() = 0;
protected:
    ICar() {}
    ~ICar() {}
};

class BenzCar : public ICar {
    BenzCar() {}
public :
    class Facory : public ICar::IFactory, public ICar::IHandler {
    public :
        virtual ICar *crearte() {
            return new BenzCar();
        }
        virtual bool is_valid(int x) {
            return x == 0;
        }
        virtual ICar *do_it() {
            return this->crearte();
        }
        virtual void test() {
            cout << "Benz test" << endl;
        }
    };
    virtual void run() {
        cout << "Benz run" << endl;
    }
};

class BmwCar : public ICar {
    BmwCar() {}
public :
    class Facory : public ICar::IFactory, public ICar::IHandler {
    public :
        virtual ICar *crearte() {
            return new BmwCar();
        }
        virtual bool is_valid(int x) {
            return x == 1;
        }
        virtual ICar *do_it() {
            return this->crearte();
        }
        virtual void test() {
            cout << "Bmw test" << endl;
        }
    };
    virtual void run() {
        cout << "Bmw run" << endl;
    }
};

class AudiCar : public ICar {
    AudiCar() {}
public :
    class Facory : public ICar::IFactory, public IHandler {
    public :
        virtual ICar *crearte() {
            return new AudiCar();
        }
        virtual bool is_valid(int x) {
            return x == 2;
        }
        virtual ICar *do_it() {
            return this->crearte();
        }
        virtual void test() {
            cout << "AudiCar test" << endl;
        }
    };
    virtual void run() {
        cout << "Audi run" << endl;
    }
};

class ChainMaster {
public :
    static ICar::IHandler *getInstance() {
        if (head == nullptr) {
            buildChain();
        }
        return head;
    }
private :
    static ICar::IHandler *head;
    static void buildChain() {
        head = new BmwCar::Facory();
        head->next = new AudiCar::Facory();
        head->next->next = new BenzCar::Facory();
        return ;
    }
};

ICar::IHandler *ChainMaster::head = nullptr;

int main() {
    srand(time(0));
    ICar *cars[10];
    for (int i = 0; i < 10; i++) {
        int req = rand() % 3;
        for (auto p = ChainMaster::getInstance(); p; p = p->next) {
            if (p->is_valid(req)) {
                cars[i] = p->do_it();
                p->test();
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        cars[i]->run();
    }
    return 0;
}
