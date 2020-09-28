 
/*************************************************************************
   > File Name: 15.args_template.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 五  2/28 19:56:02 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

template<typename T>
void print(const T &a) {
    cout << a << endl;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
    cout << a << " ";
    print(args...);
    return ;
}

template<int n, typename T, typename ...ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::getT getT;
    typedef ARG<n - 1, ARGS...> N;
};

template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...> {
    typedef T getT;
};

template<typename T>
struct ARG<0, T> {
    typedef T getT;
    typedef T finalT;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public :
    T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::N::finalT b) {
        return a + b;
    }
};

int main() {
    print(123, 23.5, "hello world", 'o');
    Test<int(double, float)> d;
    cout << d(2.3, 4.5) << endl;
    return 0;
}

