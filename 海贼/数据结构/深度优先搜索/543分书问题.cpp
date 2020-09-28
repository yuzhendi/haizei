/*************************************************************************
	> File Name: 543分书问题.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月19日 星期六 20时44分09秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
char a[25][25];
int check[25];

void dfs(int s) {
    if ( s == n) {
        ans++;
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (check[i] == 0 && a[s][i] == '1') { // 没有人选且是喜爱的书
            check[i] = 1;
            dfs(s + 1); // 下一个人开始选
            check[i] = 0; // 不选这本书的话
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
       cin >> a[i]; 
    }
    dfs(0);
    cout << ans << endl;

    return 0;
}
