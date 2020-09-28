/*************************************************************************
	> File Name: 264.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月28日 星期二 20时36分28秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
long long a[MAX_N + +5];
long long  s[MAX_N + 5], top = -1;//s[]存放下标，递增栈，坐标-->值， 反过来不可以
long long  l[MAX_N + 5], r[MAX_N + 5];
int main() {
    long long  n;
    cin >> n;
    for (long long  i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = a[n + 1] = -1;//边界添加哨兵元素
    s[top = 0] = 0;
    for (long long i =1; i <= n; i++) {
        while(a[s[top]] >= a[i]) top--;//维护递增
        l[i] = s[top];
        s[++top] = i;
    }
    for (long long i = n; i >= 1; i--) {
        while(a[s[top]] >= a[i]) top--;
        r[i] = s[top];
        s[++top] = i;
    }
    long long ans = 0;
    for (long long  i = 1; i <= n; i++) {
        ans = max(ans, a[i] * (r[i] - l[i] - 1));//以当前木板高度求的的最大举行面积
    }
    cout << ans << endl;
    return 0;
}
