/*************************************************************************
	> File Name: tree.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 16时06分39秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000
#define lowbit(x) ((x) & (-x))

int c[MAX_N + 5] = {0};

void add(int i, int val, int n) {
    while(i <= n) c[i] += val, i+= lowbit(i);
    return ;
}

int Sum(int i) {
    int sum = 0;
    while(i) sum+= c[i], i-= lowbit(i);
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {//从1开始
        int a;
        cin >> a;
        add(i, a, n);
    }
    for (int i = 1; i <= n; i++) {
        cout << "c[i] = " << c[i] << "lowbit(i) = " << lowbit(i)<< endl;
        cout << "S[i] =  "<< Sum(i) << endl;

    }
    return 0;
}
