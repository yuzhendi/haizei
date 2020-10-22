/*************************************************************************
	> File Name: 505最大整数.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月22日 星期四 18时22分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
string ans;
int n;
string str[100005];

bool cmp(string a, string b) {
    return (a + b) > (b + a); // 自定义排序，连接方法大的在前面
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    for (int i = 0; i < n; i++) cout << str[i];
    cout << endl;
    return 0;
}
