/*************************************************************************
	> File Name: template1.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月06日 星期四 11时46分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

template<typename T, typename U>
decltype(T() + U()) add(T const& a, U const& b) { // deltype: 用来推倒返回值的类型  (要调用默认构造比较，如果没有默认构造的化，就会有bug)
    return a + b;
}



int main() {
    cout << add(2 , 3) << endl;
    cout << add(2.0 , 3.3) << endl; // 隐士推倒
    cout << add<double>(2.3, 3) << endl; // 显示调用
    cout << add<int>(2.3, 3) << endl;
    cout << add(1, 2.3) << endl;
    return 0;
}
