/*************************************************************************
	> File Name: 1.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月17日 星期一 09时57分27秒
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

int main() {
    auto a2 = [](int a, int b) -> double{return a + b;};  // 也可以是返回值后置

    int n = 10; // 值捕获
    // auto a = [=](){};    表示以值的形式捕获所有外部变量，  对应的是[&]
    auto a = [n](int a, int b){return a + b + n;}; // 编译器自动生成类型
     n = 1000;
    auto b = [&n](int a, int b){ return a + b + n;}; // 引用捕获 : a b 里的n 都是1000  可以修改n的值
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

    cout << a(123, 123) << endl; // 值捕获： a b 输出内容不一样， 全是引用捕获就一样了
    cout << b(123, 123) << endl;
    
    auto c = [](function<int(int, int)> a, function<int(int, int)> b) { // lambda 也可以作为参数
        return [=](int x) { // 值捕获
            return a(x, x) + b(x, x);
        };  
    };

    auto d = c(a, b);
    cout << d(12) << endl;
    return 0;
}
