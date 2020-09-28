/*************************************************************************
	> File Name: homework.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月27日 星期一 21时05分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

namespace haizei {

    class string {
        public:

        char operator[](int ind) {
            std::string t = this->str;
            char c = t[ind];
            //cout << 'c' << endl;
            return c;
        }
        string &operator=(const string &s) {
            this->str = s.output();
            return *this;
        }
        string &operator=(const char *msg) {
            this->str = msg;
            return *this;
        }
        string operator+(const string &s) {
            std::string temp = this->str + s.output();
            string a;
            a.str = temp;
            return a;
        }
        string &operator+=(const string &s) {
            this->str += s.output();
            return *this;
        }
        int operator==(const string &a) {
            return a.str == this->str;
        }
        int operator>(const string &a) {
            return this->str > a.str;
        }
        int operator<(const string &b) {
            return this->str < b.str;
        }
        std::string output() const{
            return this->str;
        }
        int length() {
            return this->str.length();
        }
        std::string str; // 想办法变成私有的
        private:
    };
    class istream{
    public:
        istream &operator>>(haizei::string &s) {
            std::cin >> s.str;
            return *this;
        }
    private:

    };
    class ostream{
    public:
        ostream &operator<<(const haizei::string &s) { // 加&引用，防止多余的拷贝
            std::cout<< "haizei : ";
            std::cout << s.output();
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

ostream &operator<<(ostream &out, const haizei::string &s) {
    std::cout << s.output();
    return out;
}
    

int main() {
     haizei::string test, t2;
    cout << "字符串直接赋值:  test = abc  ";
    test = "abc";
    cout << test << endl;
    cout << "string = :  t2 = test:  ";
    t2 = test;
    cout << t2 << endl;
    cout << "t2 += t2:  ";
    t2 += t2;
    cout << t2 << endl;
    cout << "t2 = test + t2:  ";
    t2 = test + t2;
    cout << t2<< endl;
    haizei::string t3;
    cout << "haizei::cin>>t3:   ";
    haizei::cin >> t3;
    haizei::cout << "t3 = " << t3 << "\n";
    cout << endl;
    cout << "t2 == t3 :  ";
    cout << (t2 == t3) << endl;
    cout << "t2 > t3:  " ;
    cout << (t2 > t3) << endl;
    cout << "t2 < t3:   " ;
    cout << (t2 < t3) << endl;
    std::string c = "ddd";
    cout << "t2[0]:  ";
    cout << t2[0] << endl;
    cout << "t3.length():  ";
    cout << t3.length() << endl;
    return 0;
}
