/*************************************************************************
	> File Name: args.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月06日 星期四 16时25分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
namespace haizei{
template<typename T>
    void printAny(const T &a) {
        cout << a << endl;
        return ;
    }
template<typename T, typename ...ARGS> // ARGS表示类型包
void printAny(const T &a, ARGS... args) {
    cout << a << "  ";
    printAny(args...); // 递归打印 , 当到 1 的时候会调用上面定义的模板， 防止无限止的循环出错 
    return ;
}
/*
template<typename T, typename ...ARGS>
struct ARG {
        typedef T __type; // 给第一个参数和剩余的参数起别名
        typedef ARG<ARGS...>  __rest;
};
template<typename T>
    struct ARG<T>{
        typedef T __type; //最后只有一个参数时
    };
*/

template<int n, typename T, typename ...ARGS>
struct ARG{
    typedef typename ARG<n - 1, ARGS...>::getT getT; // 一般类型，查找n - 1的下个T 
    typedef  ARG<n - 1, ARGS...> N; // 寻找最后一个数据的时候
};

template <typename T, typename ...ARGS>
    struct ARG<0, T, ARGS...> { // 特化模板， 找第一个参数
        typedef T getT;
    };
template <typename T>
    struct ARG<0, T> { // 特化模板
        typedef T getT; // 找第一个参数， 当且仅有一个参数
        typedef T finalT; // 最后一个参数的终止
    };

template<typename T, typename ...ARGS> class Test; // 一般模板类
template <typename T, typename ...ARGS>
    class Test<T(ARGS...)> { // 特化模板类， 类似函数传参， 返回类型为T， 参数类型为ARGS
    public :
        T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::N::finalT b) {
        return a + b;
    }
    };
}
int main() {
    int a = 0;
    haizei::printAny(123, 34.5, "Hello word!", &a);
    haizei::Test<int(double, int)> b;
    haizei::printAny(b(2.3, 4));
    
    return 0;
}
