/*************************************************************************
	> File Name: test.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月12日 星期三 18时12分39秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[5] = {1, 2, 3 ,4 ,5};
    int *p = (int *)(&a + 1);
    cout << *(a + 1) << " " << *(p - 1) << endl;;
    return 0;
}
