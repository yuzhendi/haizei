/*************************************************************************
	> File Name: 251.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月17日 星期日 20时51分08秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10000
int x[MAX_N + 5];
int w[MAX_N + 5];
int y[MAX_N + 5];

int n;

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(y, y + n);
    sort(x, x + n);
    for (int i =  0; i < n; i++) w[i] = x[i] - i;
    sort(w, w + n);
    int sum = 0, cy = y[ n >> 1 ], cw = w[n >> 1];
    
    for (int i = 0; i < n; i++) {
        sum += abs(cy - y[i]);
        sum += abs(w[i] - cw);
    }
    cout << sum << endl;


    return 0;
}
