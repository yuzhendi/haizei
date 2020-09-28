/*************************************************************************
	> File Name: args2..cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月08日 星期六 09时25分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


template<int n, typename T, typename ...ARGS> 
struct ARG{
    typedef typename ARG<n - 1, ARGS...>::__type __type;
};
template<typename T, typename ...ARGS>
struct ARG <0, T, ARGS...>{ // 递归的终止条件
    typedef T __type;
};

template<typename T>
struct ARG<0, T> { // 只有一个参数的情况时取第一个参数 就是 最后一个参数
    typedef T __type;
    typedef T __fin; // 判断是否是最后一个
};


template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public:
    T operator()(ARGS... args) {
        return add<T>(args...);
    }
private:
    template<typename T1, typename U, typename ...US>
    T1 add(U a, US ...args) {
        return a + add<T1>(args...);
    }
    template<typename T1, typename U>
    T1 add(U a) {
        return a;
    }
};

template<typename T, typename U>
T test(U b) {
    return T(b + 2);
}
void fun2(int (*func)(double)) { // 模板函数作为参数传递时也可以作为类型推导
    cout << func(2.3) << endl;
}
template <typename T>struct remove_referenc { // 返回正常的类型
    typedef T type;
};

template <typename T> struct remove_referenc<T &> { // 将左值引用去掉引用
    typedef T type;
};
template <typename T> struct remove_referenc<T &&> { // 将右值引用去掉
    typedef T type;
};

template <typename T>
typename remove_referenc<T>::type add2(T &&a, T &&b) { // 引用
    typename remove_referenc<T>::type c = a + b; // 加法产生的是右值
    return c;
}
//引用折叠
//模板中有两个&& 时，表示的是传递的是引用（编译器有一个类型推导的过程）， 具体是左值引用还是右值引用还要看T的类型， 奇数&是左值引用，偶数&是右值引用


int main() {
    fun2(test); //模板函数作为参数进行间接类型推导
   Test<int(double, float)> test;
    cout << test(2.3, 4) << endl;
    int a = 3, b = 3;
    cout << add2(a, b) << endl; // 引用推导： add2(int&, int&)
    //cout << add2(3, 4) << endl; 报错，传入的是左值
    return 0;
}
