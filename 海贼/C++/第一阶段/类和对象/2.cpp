/*************************************************************************
	> File Name: 2.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月26日 星期日 19时43分57秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class Point {
public :
    Point(){
        Point::total_cnt += 1;
    }
    Point(int x, int y) : Point(){ // 显示调用Point构造函数
        this->x = x;
        this->y = y;
    }
    ~Point() {
        Point::total_cnt -= 1;
    }
    static int T() {
        return Point::total_cnt;
    }
private:
    int x, y;
    static int total_cnt;// 类属性
};
int Point::total_cnt = 0;
void test() {
    Point a;
    cout << Point::T() << endl;
    return ;
}
int main() {
    Point a;
    cout << a.T() << endl;
    test();
    Point b;
    cout << b.T() << endl;
    return 0;
}
