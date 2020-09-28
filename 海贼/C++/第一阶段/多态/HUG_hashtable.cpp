/*************************************************************************
	> File Name: 21.hash_table.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 六  8/ 1 19:13:10 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

namespace haizei {// 在一个命名空间里面构造自己的类型

class IHashFunc {
public :
    virtual int operator()(int) = 0; // 函数对象
};

class HashTable {
    typedef int (*HashFunc_T)(int);
    typedef pair<int, int> PII;
public :
    HashTable(HashFunc_T); // 传入函数
    HashTable(IHashFunc &); // 传入对象的引用
    int &operator[](int);

private:
    HashTable(HashFunc_T, IHashFunc *, int); // 定义在private里面， 构造时不能直接使用， 但是可以被其他构造函数调用
    int hash_type;
    HashFunc_T func1; // 函数
    IHashFunc *func2; // 对象

    int __size;
    PII **data; // 成对出现
};

HashTable::HashTable(HashFunc_T func1, IHashFunc *func2, int hash_type) 
: func1(func1), func2(func2), hash_type(hash_type) { // private 里的构造函数
    this->__size = 1000;
    this->data = new PII*[this->__size];
    for (int i = 0; i < this->__size; i++) this->data[i] = nullptr; // 初始化指针指向空
}

HashTable::HashTable(HashFunc_T func) 
: HashTable(func, nullptr, 1) {} // 传入函数， 调用构造

HashTable::HashTable(IHashFunc &func) 
: HashTable(nullptr, &func, 2) {}


int &HashTable::operator[](int x) { // 返回引用：直接将x赋值 hash[123] = x
    int hash = 0;
    switch (hash_type) {
        case 1: hash = func1(x); break;
        case 2: hash = (*func2)(x); break;
    }
    if (hash < 0) hash &= 0x7fffffff;
    int ind = hash % __size, t = 1;
    while (data[ind] && data[ind]->first != x) { // 散列法解决冲突
        ind += t * t;
        if (ind < 0) ind = ind & 0x7fffffff;
        ind %= __size;
        t += 1;
    }
    if (data[ind] == nullptr) data[ind] = new PII(x, 0); // 没有找到就新建一个
    return data[ind]->second;
}

} // end of namespace haizei

int hash1(int x) {
    return (x << 1) ^ (x << 3) ^ (x >> 5);
}

class MyHashFunc : public haizei::IHashFunc { // 从接口里构造一个哈希函数
public :
    int operator()(int x) override {
        return (x << 1) ^ (x << 3) ^ (x >> 5);
    }
};

int main() {
    MyHashFunc hash2;
    haizei::HashTable h1(hash1);
    haizei::HashTable h2(hash2);
    h1[123] = 345;
    h2[123] = 678;
    cout << h1[123] << endl;
    cout << h2[123] << endl;
    cout << h1[789] << endl;
    cout << h2[1000000] << endl;
    return 0;
}
