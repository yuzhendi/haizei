/*************************************************************************
	> File Name: 600.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月20日 星期三 20时09分02秒
 ************************************************************************/
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, t;
int num[3005][3005];    


int main() {
    scanf("%d%d%d",&n,&m,&t);//数据比较多，用scanf；cin较慢
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d",&num[i][j]);
        }
    }
    int i = n, j = 1;
    while(i > 0 && j <= m) {//左下角开始
        if (num[i][j] == t) {
            printf("%d %d\n",i, j);
            return 0;
        } else if (num[i][j] < t) {
            j++;
        } else {
            i--;
        }
    }
    return 0;
}
