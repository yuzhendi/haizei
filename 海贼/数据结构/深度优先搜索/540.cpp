/*************************************************************************
	> File Name: 540.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月17日 星期四 20时06分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int cost, n;
int price[45];
int set[2][3000005], cnt[2];

void dfs(int set_num, int s, int e, int sum) {
    if (sum > cost) return ;
    for (int i = s; i < e; i++) {
        sum += price[i];
        set[set_num][cnt[set_num]] = sum;
        cnt[set_num]++;  
        dfs(set_num, i + 1, e, sum);
        sum -= price[i];

    }
}

/*             正常做法会超时        
bool cmp(int a, int b) {
    return a < b;
}

int dfs(int s, int left) {
    if (left == 0) return 1;
    if (left < price[s] || s >= n) return 0;
    for (int i = s; i < n; i++) {
        if (dfs(i + 1, left - price[i])) return 1;
    }
    return 0;
}

int main() {
    while((scanf("%d%d", &n,&x)) != EOF) {
    //cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> price[i]; 
    }
    sort(price, price + n, cmp);
    if (dfs(0, x)) cout << "YES" << endl;
    else cout << "NO" << endl;
    }
    return 0;
}*/

/******   思想 ： 将价格分成前后两半分别深搜，记录其所有和的值，  最后看前后有没有两个数相加得到x ,（二分） */

int main() {
    while(cin >> n >> cost) {
            int flag = 0;
        
        cnt[0] = cnt[1] = 1;
        for (int i = 0; i < n; i++) {
            cin >> price[i];
        }
        dfs(0, 0, n / 2, 0); 
        dfs(1, n / 2, n, 0); 
        sort(set[1], set[1] + cnt[1]);
        for (int i = 0; i < cnt[0]; i++) {
            int target = cost - set[0][i];
            int l = 0, r = cnt[1] - 1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if (set[1][mid] == target) {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
                else if (set[1][mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
                if (flag == 1) break;

            }
            if (flag == 1) break;
        }
        if (flag == 0) cout << "NO" << endl;
    }


    return 0;
}
