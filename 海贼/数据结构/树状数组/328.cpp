/*************************************************************************
	> File Name: tree.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 16时06分39秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 1000
#define lowbit(x) ((x) & (-x))

int c[MAX_N + 5] = {0};// 存放那个先小后大的 前面的数
int d[MAX_N + 1] = {0};
int num1[MAX_N + 1] = {0};// i 前面小于a[i]的数
int num2[MAX_N + 1] = {0};
void add(int i, int val, int n, int No) {
    if (No == 1)
        while(i <= n) c[i] += val, i += lowbit(i);//先小后大
    else 
        while(i <= n) d[i] += val, i+= lowbit(i);// ^
    return ;
}

int Sum(int i, int No) {
    int sum = 0;
    if (No == 1)    
        while(i) sum += c[i], i -= lowbit(i);
    else 
        while(i) sum += d[i], i -= lowbit(i);
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {//从1开始
        int val;
        cin >> val;
        num1[i] = Sum(val, 1);
        num2[i] = Sum(n - val, 2);
        cout << "num1 : " << num1[i] << endl;
        cout << "num2 : " <<  num2[i] << endl;
        add(val, 1, n, 1);//现在c[i]存放前i个位置比他小的
    }
    /*for (int i = 0; i <= n + 1; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) {
        num2[i] = Sum(n - a[i], 1);
        cout << "num2[" << i  <<"] = " << num2[i] << endl;
        add(n - a[i], 1, n, 2);
        continue;
    }*/
    for (int i = 1; i <= n; i++) {
        cout << num1[i] <<"  " << num2[i] << endl;
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        sum1 += (num1[i] * num2[i]);
        sum2 += ((i - num1[i]) * (( i - num2[i])));
    }
    cout << num1 << num2 << endl;
    /* for (int i = 1; i <= n; i++) {
        cout << "c[i] = " << c[i] << "lowbit(i) = " << lowbit(i)<< endl;
        cout << "S[i] =  "<< Sum(i) << endl;

    }*/
    return 0;
}
