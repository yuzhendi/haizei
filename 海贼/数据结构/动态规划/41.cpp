/*************************************************************************
	> File Name: 41.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月26日 星期日 20时30分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

int f[1005][1005][1005];
//f[t][i][j]:长为t的墙i-j的种数1=i,n=j时
//f[t][i][j] = *f[t-1][i][j-1]
//第j-1所有情况的和（此时 第j块的强为j且num[j-1] != j

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            f[1][i][j] = (i == j);
        }
    }
    for (int t = 2; i <= n; t++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                for (int l = 0; l < k; l++) {
                    if (l - j) f[t][i][j] += f[t - 1][i][l];
                }
            }
        }
    } 
    int ans = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; i < k; j++) {
            if (l - j) ans += f[n][i][j];
        }
    }
    cou << ans << endl;
    return 0;
}
