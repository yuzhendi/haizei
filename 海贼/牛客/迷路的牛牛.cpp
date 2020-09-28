/*************************************************************************
	> File Name: 迷路的牛牛.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月19日 星期三 16时25分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int num = 0;
    for (int i = 0; i < n; i++) {
        switch(s[i]) {
            case 'L': num -= 1; break;
            case 'R': num += 1; break;
        }
    }
    num = abs(num);
    num %= 4;
    if (num == 0) {
        cout << 'N' << endl;
    } else if (num == 1){
        cout << 'E' << endl;
    } else if (num == 2) {
        cout << 'S' << endl;
    } else {
        cout << 'W' << endl;
    }


    return 0;
}
