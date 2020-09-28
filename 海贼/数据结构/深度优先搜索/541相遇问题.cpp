/*************************************************************************
	> File Name: 541相遇问题.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月19日 星期六 20时29分28秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, atime[2][20][20], ans[2][100005], ans_num[2];

void func(int people, int loc, int cost) {
    if (loc == n) {
        ans[people][ans_num[people]] = cost;
        ans_num[people]++;
        return ;
    }
    for (int i = loc + 1; i <= n; i++) {
        if (atime[people][loc][i]) {
            func(people, i, cost + atime[people][loc][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        atime[0][a][b] = atime[0][b][a] = c;
        atime[1][a][b] = atime[1][b][a] = d;
    }
    func(0, 1, 0);
    func(1, 1, 0);
    sort(ans[0], ans[0] + ans_num[0]);
    sort(ans[1], ans[1] + ans_num[1]);
    for (int i = 0; i < ans_num[0]; i++) {
        for (int j = 0; j < ans_num[1]; j++) {
            if (ans[0][i] == ans[1][j]) {
                cout << ans[0][i] << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
