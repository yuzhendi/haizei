/*************************************************************************
	> File Name: 237.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月27日 星期四 21时13分55秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n, num[15], mark[15], cnt;

void func(int left) {
    if (left == 0) { // 没有剩余的数
        for (int i = 0; i < cnt; i++) {
            if (i) cout << " ";
            cout << num[i];
        }
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n; i++) { //每次都要从1-n
        if (mark[i] == 0) { //未被选中的数，防止重复调用
            num[cnt++] = i;        
            mark[i] = 1;
            func(left - 1);
            cnt--;
            mark[i] = 0;
        }
    }
}


int main() {
    cin >> n;
    func(n);


    return 0;
}
