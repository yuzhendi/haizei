/*************************************************************************
	> File Name: homework.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月08日 星期六 12时09分12秒
 ************************************************************************/

#include <iostream>
#include <typeinfo>
using namespace std;

namespace haizei {
/*******************去除引用********************************/
//引用折叠
template<typename T> struct remove_reference { typedef T type; };
template<typename T> struct remove_reference<T &> { typedef T type; }; //
template<typename T> struct remove_reference<T &&> { typedef T type; };

/********  add_const:    添加const限定***********************/
// cosnt 也有折叠
template<typename T> struct add_const{ typedef const T type; }; // 普通类型
template<typename T> struct add_const<const T>{ typedef const T type; }; // 匹配const T


/********add_lvalue_reference: 转换成左值引用****************/
template<typename T> struct add_lvalue_reference{ typedef T& type; }; // 一般类型直接转换成左值引用
template<typename T> struct add_lvalue_reference<T &> { typedef T& type; };
template<typename T> struct add_lvalue_reference<T &&> { typedef T& type; };

/*******add_rvalue_reference: 转换右值引用*******************/

template<typename T> struct add_rvalue_reference{ typedef T&& type; }; // 
template<typename T> struct add_rvalue_reference<T &> { typedef T&& type; };
template<typename T> struct add_rvalue_reference<T &&> { typedef T&& type; };

/*******remove_pointer: 去掉指针类型***************************/
template<typename T> struct remove_pointer{ typedef T type; }; // 非指针类型直接返回
template<typename T> struct remove_pointer<T *> { typedef  typename remove_pointer<T>::type type; };
/*****************************move()****************************/
template<typename T>
    typename add_rvalue_reference<T>::type move(T &&a) { // 两个&&表示传入的是引用 传值的话不会对a进行绑定
        return typename add_rvalue_reference<T>::type(a); // 强转右值
    }


/********************test************************************/
template <typename T>
typename remove_pointer<T>::type output(T a) {
    cout << a << "sucess" << endl;
    return 0;
}

void f(int &x) {
    cout << "l_value" << endl;
}
void f(int &&x) {
    cout << "r_value" << endl;
}
}

int main() {
    int a = 1, b = 2;
    int *p = &a;
    int **q = &p;
    haizei::output(&a);
    haizei::f(a);
    haizei::f(haizei::move(a));
    return 0;
}
