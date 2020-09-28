/*************************************************************************
	> File Name: 2.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月27日 星期一 19时21分04秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class Point {
public:
    Point() : __x(0), __y(0){} // 默认初始化列表
    Point(int x, int y) : __x(x), __y(y){};
    int x() const {return __x;}
    int y() const {return __y;}
    Point operator+(const Point &a) { //返回一个新的值， 不能用引用
        return Point(this->__x + a.x(), this->__y + a.y());
    }
    //void operator+=(const Point &a) {
    Point &operator+=(const Point &a) { // 最好返回当前对象的引用： (a+=b)++ 可以使用
        this->__x += a.x();
        this->__y += a.y();
        return *this;
    }
    Point &operator++() { // ++a (前)
        this->__x++;
        this->__y++;
        return *this;
    }
    Point operator++(int) { // a++（后)  // 不能返回引用， 引用是一个标签，temp生存周期只在此函数
        Point temp(*this);
        __x++;
        __y++;
        return temp;
    }
private:
    int __x, __y;
};

ostream &operator<<(ostream &out, const Point &a) {
    out <<"Point (" << a.x() << " ," << a.y() << ")";
    return out;
}

int main() {
    Point a(1, 2), b(3, 4), c(3, 3);
    cout << "a: "<< a << "  b : " << b <<"  c: "<< c << endl;
    cout << "a + b: " << a + b << endl;
    cout << "++(c += b) : " << ++(c += b) << endl;
    cout << "c++: "; 
    cout << c++ << endl;
    return 0;
}
