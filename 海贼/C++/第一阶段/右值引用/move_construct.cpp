/*************************************************************************
	> File Name: move_construct.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月06日 星期四 09时40分59秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

namespace haizei {
    class string {
        public :
        string() {
            cout << "默认构造 :" << this<< endl;
            this->__length = 0;
            this->__end = '\0';
            this->__buff_size = 10;
            this->buff = new char[this->__buff_size];
        }
        string(const char *str) {
            cout << "char * 构造: " << this << endl;
            this->__buff_size = strlen(str) + 1;
            this->buff = new char[this->__buff_size];
            strcpy(this->buff, str);
            this->__length = this->__buff_size - 1;
        }
        char &at(int ind) {
            if (ind < 0 || ind >= __length) {
                cout << "String Error: out_of_range" << endl;
                return __end;
            }
            return this->operator[](ind);
        }
        char &operator[](int ind) {
            return this->buff[ind];
        }
        const char *c_str() const{
            return buff;
        }
        string operator+(const string &s) {
            cout << " + " << endl;
            int size = this->__length + s.__length + 1;
            char *temp = new char[size];
            strcpy(temp, this->buff);
            strcat(temp, s.buff);
            return temp;
        }
        string(const string &str) {
            cout << "左值引用构造 " << this << endl;
            this->__buff_size = str.__buff_size;
            this->__length = str.__length;
            this->buff = new char[str.__buff_size];
            
            for (int i = 0; i < this->__length; i++) {
                this->buff[i] = str.buff[i];
            }
            
        }
        string(string &&str) { // 右值引用
            cout << "move construct, " << this << endl;
            this->__buff_size = str.__buff_size;
            this->__length = str.__length;
            this->buff = str.buff; // 移动指针
            str.buff = nullptr;
        }
        int size() {
            return this->__buff_size;
        }
        ~string() {
            cout << "析构函数 " << this << endl;
            if (buff != nullptr) delete buff;
        }
        private:
        int __length, __buff_size;
        char *buff; // 默认拷贝是浅拷贝
        char __end;
    };
}

ostream &operator<<(ostream &out,const haizei::string &s) {
    cout << s.c_str() << endl;
    return out;
}

int main() {
    haizei::string s = "hello world", s1 = " s1 ", s2  = " s2 ";
    cout << "/*****************************/" << endl;
    cout << " s3 = s + s1 + s2 :  " << endl; // 在构造函数里面写上输出，来批判一下这条语句的运行流程->  1:s + s1 然后执行默认构造函数(一次拷贝), 2: + s2赋值匿名变量， 赋值给s3
    haizei::string s3 = s + s1 + s2;
    cout << s3 << endl;
    cout << "/****************************/" << endl << endl;
    haizei::string s5 = s3;
    s3[3] = '=';
    cout << "s3:  " << s3 <<endl;
    cout << "s5:   " << s5 << endl;
    cout << s << endl;
    s[3] = '5';
    cout << s << endl;
    cout << s + s1 << endl;

    return 0;
}



