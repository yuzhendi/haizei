/*************************************************************************
    > File Name: 545导弹拦截.cpp
    > Author: yu zhen di
    > Mail: 1316215578@qq.com
    > Created Time: 2020年09月19日 星期六 21时14分25秒
    check[loc] = 1;
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
/*   问题1 ： 求最长不上升子序列即可  */
/*   问题2 ： 求最长上升子序列即可  */

int n, num[3005][3]; // 第一层存数据， 第二层存第一问， 第三层存第二问
// 求最长上升子序列， 用到了dp动态规划

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i][0];
    }
    for (int i = 0; i <= n ; i++) {
        int f  = 0;
        for (int j = i - 1; j >= 0; j--) {
            if(num[j][1] >= num[i][1] && num[j][0] >= num[i][0]) {
                f = 1;
                num[i][1] = num[j][1] + 1;
            }
        }
        if (f == 0) {
            num[i][1] = 1; // 是到 i 为止最大的数
        }
    }
    for (int i = 0; i <= n ; i++) {
        int f  = 0;
        for (int j = i - 1; j >= 0; j--) {
            if(num[j][2] >= num[i][2] && num[j][0] <= num[i][0]) {
                f = 1;
                num[i][2] = num[j][2] + 1;
            }
        }
        if (f == 0) {
            num[i][2] = 1; // 是到 i 为止最大的数
        }
    }
       int ans1 = 0, ans2 = 0;
    for (int i = 1; i < n; i++) {
        if (num[i][1] > num[ans1][1]) ans1 = i;
        if (num[i][2] > num[ans2][2]) ans2 = i;
    }
    cout << num[ans1][1] << endl << num[ans2][2] << endl;
    return 0;
}


/*
int h[1005], ans1, ans2;
int n;
void dfs1(int s, int sum) {
    if (s + ans1 == n - 1) return ;
    for (int i = s + 1; i < n; i++) {
        if (h[i] <= h[s]) {
            dfs1(i, sum + 1);
        }
    }
    ans1 = max(ans1, sum);
}
void dfs2(int s, int sum) {
    if (s + ans2 == n - 1) return ;
    for (int i = s + 1; i < n; i++) {
        if (h[i] >= h[s]) {
            dfs2(i, sum + 1);
        }
    }
    ans2 = max(ans2, sum);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        dfs1(i, 1);
        dfs2(i, 1);

    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}*/
