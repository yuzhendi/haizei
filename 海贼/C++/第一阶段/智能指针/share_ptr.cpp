/*************************************************************************
	> File Name: share_ptr.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月20日 星期四 15时32分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
namespace haizei {
class A {
public:
    A() : x(1), y(3){}
    int x, y;
    ~A() {
        cout << "destroy A" << endl;
    }
};
template<typename T>

class shared_ptr {
public:
    shared_ptr() : ptr(nullptr), pcnt(nullptr){}
    shared_ptr(T *ptr) : ptr(ptr), pcnt(new int(1)){}
    shared_ptr(const shared_ptr<T> &p) : ptr(p.ptr), pcnt(p.pcnt){
        *pcnt += 1; // 计数器
    }
    shared_ptr<T> &operator=(shared_ptr<T> &p) {
        if (pcnt) {
            *pcnt -= 1;
            if (*pcnt == 0) {
                delete ptr;
            }
        }
        this->ptr = p.ptr;
        this->pcnt = p.pcnt;
        *pcnt += 1;
        return *this;
    }
    int use_count(){
        return (pcnt ? *pcnt : 0);
    }
    T &operator*() {return *(this->ptr);}
    T *operator->() {return this->ptr;}
    ~shared_ptr() {
        if (pcnt) {
            *pcnt -= 1;
            if (*pcnt == 0) {
                delete ptr; // 引用计数为0， 将对象析构
                delete pcnt;
            }
        }
    }
private:
    T *ptr;
    int *pcnt;

};

}

int main() {
    haizei::shared_ptr<haizei::A> p(new haizei::A()), q = p;
    haizei::shared_ptr<haizei::A> k(new haizei::A());
    cout << p->x << " " << p->y << endl;
    cout << q->x << " " << q->y << endl;
    cout << p.use_count() << endl; 
    q = k;
    cout << p.use_count() << endl; 
    p = k;
    cout << p.use_count() << endl;
    return 0;
}
