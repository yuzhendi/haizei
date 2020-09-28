/*************************************************************************
	> File Name: lambda.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月14日 星期五 17时47分13秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

auto add = [](int a, int b) -> long long {
    return a + b;
};

auto Data = [](int a, int b) {
    return [=](auto func) {
        return func(a, b);
    };
};

auto First = [](int a, int b) {
    return a;
};

auto Second = [](int a, int b) {
    return b;
};

auto Add = [](int a, int b) {
    return a + b;
};

auto Max = [](int a, int b) {
    return max(a, b);
};

auto is_in = [](int a, int b) {
    return [=](int x) {
        return a <= x && x <= b;
    };
};

auto OR = [](auto u, auto v) {
    return [=](int x) {
        return u(x) || v(x);
    };
};

auto NOT = [](auto u) {
    return [=](int x) {
        return !u(x);
    };
};

auto is_little = is_in('a', 'z');
auto is_upper = is_in('A', 'Z');
auto is_digit = is_in('0', '9');
auto is_alpha = OR(is_little, is_upper);
auto other = NOT(is_alpha);


int main() {
    cout << is_little('A') << endl;
    cout << is_little('a') << endl;
    cout << is_alpha('a') << endl;
    cout << is_alpha('A') << endl;
    cout << other('A') << endl;
    cout << other('9') << endl;
    cout << add(2, 4) << endl;
    auto a = Data(rand() % 1000, rand() % 1000);
    cout << a(First) << endl;
    cout << a(Second) << endl;
    cout << a(Add) << endl;
    cout << a(Max) << endl;
    return 0;
}
