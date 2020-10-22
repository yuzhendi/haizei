/*************************************************************************
	> File Name: test.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月30日 星期三 11时12分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct string {
    char val;
    struct string *next;
}string;

void init(string &c, int n) {
    *c = (string *)malloc(sizeof(string));
    c->next = NULL;
    return ;
}

int main() {
    string *c;
    init(c, 1);
    printf("%d ", c->next);
    return 0;
}
