/*************************************************************************
	> File Name: 1.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月27日 星期一 18时29分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

namespace haizei {
    class istream{
    public:
        istream &operator>>(int &n) {
            std::cin >> n;
            return *this;
        }
    private:

    };
    class ostream{
    public:
        ostream &operator<<(int &n) { // 加&引用，防止多余的拷贝
            std::cout<< "haizei : ";
            std::cout << n;
            return *this;
        }
        ostream &operator<<(const char *msg) { // string 是一个类， 如果写string的话，要有一个char *到string 的构造，变慢
            std::cout << msg;
            return *this;
        }

    private:

    };
    istream cin;
    ostream cout;

}

haizei::ostream &operator<<(haizei::ostream &out, double &k) {
    std::cout << k;
    return out;
}
ostream &operator+(ostream &out,const int &n) { // 必须加入const, 不可修改 常量 n
    std::cout << n;
    return out;
}
int main() {
    int n, m;
    //haizei::cin >> n >> m; //返回void operator>> 类型 不支持连续读 
    haizei::cin >> n >> m; // haizei::cin.operator(n)
    haizei::cout << n << " " << m << "\n";
    double k = 5.6;
    haizei::cout << k << "\n";
    ((((cout + 3) << " ") + 4 )<< " ") + 5;
    return 0;
}
