/*************************************************************************
	> File Name: Hash_table.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月01日 星期六 19时13分31秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
namespace haizei{
class IHashFunc {
public:
    virtual int operator()(int) = 0;
};

class HashTable {
    typedef int (*HashFunc_T)(int);
    typedef pair<int,int> PII;
public:
    HashTable(HashFunc_T func);
    HashTable(IHashFunc &func);
    int &operator[](int x);
private:
    HashTable(HashFunc_T, IHashFunc *, int); // 默认构造函数放在private里面， 本身不能使用，但是其他构造函数可以使用
    int hash_type;
    HashFunc_T func1;
    IHashFunc *func2;
    int __size;
    PII *data;
};
HashTable::HashTable(HashFunc_T func1, IHashFunc &func2, int hash_type)
:func1(func1), func2(func2),hash_type(hash_type){
    this->__size = 1000;
    this->data = new PII[this->size];
    for (int i = 0; i < this->size; i++) this->data[i] = nullptr;//初始化指针指向空
}
HashTable::int &operator[](int x) {
    int hash = 0;
    switch (hash_type) {
            case 1:hash = func1(x);break;
            case 2:hash = (*)func2(x);break;
        }
        int ind = hash % __size;
        int t = 1;
        if (hash < 0) hash = hash & 0x3fffffff;
        while (data[i] && data[ind]->firse != x) {
            ind += t * t;
            t += 1;
            if (ind < 0) ind = ind & 0x3fffffff;
            ind %= __size;
        }
        if (data[ind] == nullptr) data[ind] = new PII(x, 0); // 没有就新增一个节点
    }

HashTable::HashTable(HashFunc_T func) : func1(func) {
    hash_type = 1;
}
HashTable::IHashTable(Hash)
}
int hash1(int x) {
    return (x * 2 - 1);
}

int main() {
    HashTable h1(hash1);
    HashTable h2()
    

    return 0;
}
