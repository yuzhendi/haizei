/*************************************************************************
	> File Name: string.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月01日 星期六 14时32分09秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

namespace haizei {
    class string {
        public :
        string() {
            this->__length = 0;
            this->__end = '\0';
            this->__buff_size = 10;
            this->buff = new char[this->__buff_size];
        }
        string(const char *str) {
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
            int size = this->__length + s.__length + 1;
            char *temp = new char[size];
            strcpy(temp, this->buff);
            strcat(temp, s.buff);
            return temp;
        }
        int size() {
            return this->__buff_size;
        }
        private:
        int __length, __buff_size;
        char *buff;
        char __end;
    };
}

ostream &operator<<(ostream &out,const haizei::string &s) {
    cout << s.c_str() << endl;
    return out;
}

int main() {
    haizei::string s = "hello world", s1 = "haizei";
    cout << s << endl;
    s[3] = '5';
    cout << s << endl;
    cout << s + s1 << endl;

    return 0;
}
