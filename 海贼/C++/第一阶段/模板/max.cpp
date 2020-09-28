/*************************************************************************
	> File Name: max.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月06日 星期四 12时19分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

namespace haizei {
    class Max{
        
    public:
        template<typename T, typename U>
        auto operator()(T const &a, U const &b) -> decltype((a < b) ? b : a) {
            return a < b ? b : a;
        }
    };
}

class printAny {
public :
    template<typename T>
    void operator()(const &T a){ // template 下的是模板， 这个为模板函数
        cout << a << endl;
    }
};

int main() {
    haizei::Max  max;
    cout << max(4, 2) << endl;
    cout << max(1, 2.2) << endl;

    return 0;
}
