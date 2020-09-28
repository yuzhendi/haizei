/*************************************************************************
	> File Name: KMP.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月25日 星期六 20时58分44秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#define MAX_N 1000
char text[MAX_N + 5], pattern[MAX_N + 5];

int brute_force(char *s, char *t) {
    //暴力算法 s 中找 t
    int len1 = strlen(s);
    int len2 = strlen(t);
    for(int i = 0; len1 - len2 + 1; i++) {
        int flag = 1;
        for (int j = 0; t[j]; j++) {
            if (s[i + j] == 0) {
                flag = 2;
                break;
            }
            
            if (t[j] == s[i + j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}


int main() {
    scanf("%s%s", text, pattern);

    return 0;
}
