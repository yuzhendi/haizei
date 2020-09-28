/*************************************************************************
	> File Name: 243.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月17日 星期日 18时59分24秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 2000000

struct Data {
    int s, e , d, c;// c 存放人数和
}arr[MAX_N + 5];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].e >> arr[i].d;
        arr[i].c = (arr[i].e - arr[i].s) / arr[i].d + 1;
        if (i == 0) {
            l = arr[i].s, r= arr[i].e;
            l = min(l, arr[i].s);
            r = max(r, arr[i].e);
        }
    }
    itn ans = bs(l , r);

}

int main() {
    int tcase;
    cin >> tcase;
    while(tcase--) {
        solve();
    }
    return 0;
}
