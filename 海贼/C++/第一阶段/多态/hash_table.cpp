/*************************************************************************
	> File Name: hash_table.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月01日 星期六 18时46分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class Hash{
public:
    Hash = delete;
    Hash (void &func) {
       //this->func = &func;
        (void **)this[0][0] = &func;
        store_string = new string[100];
        store_int = new int[100];
    }
    virtual void use_func(){}; // 只占一个位置，作为找寻哈希函数用
    string find(int x) { // 通过整型找整型
        int t = int((void **)this[0][0](x));
        return this->store_int[t];
    }
private:
    int ind;
    string *store_string;
    int *store_int;
    void *func;
};
int h_func(int x) {
    
}


int main() {
    


    return 0;
}
