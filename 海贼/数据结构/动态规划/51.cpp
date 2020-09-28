/*************************************************************************
	> File Name: 51.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月13日 星期三 12时41分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000
int a[MAX_N + 5], f[MAX_N + 5];//a 存放当前矩形向下数连续的白色矩形数量
//f 数组存放当前矩形作为右上角时，所拥有的最大矩形数量
int s[MAX_N + 5], top = -1, val;//利用单调栈
/*每一个矩形作为右上角，找到符合条件的左下角，
 * 直到当前行向下数连续的白色矩形小于这一个矩形*/
int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    a[m + 1] = -1;
    f[m + 1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> val;
            if (val == 1) a[j] += 1;
            else a[j] = 0;
        }
        top = -1;//每一行都要初始化
        s[++top] = m + 1;//初始最大值
        for (int j = m; j >= 1; j--) {
            while(a[s[top]]>= a[j]) top--;//单调队列找到第一个小于a[j]的位值
            f[j] = (s[top] - j) * a[j] + f[s[top]];
            f[j] %= 100007;
            s[++top] = j;
            ans += f[j];
            ans %= 100007;
        }
    }
    cout << ans << endl;

    return 0;
}
