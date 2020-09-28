/*************************************************************************
	> File Name: trie.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月05日 星期二 21时53分25秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#define BASE 26
#define BASE_LETTER 'a'

typedef struct Node {
    int flag;//判断此处是否独立成词
    struct Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

inline int code(char ch) {//inline 是内联函数，相当于宏定义
    return ch - BASE_LETTER;
}


void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[code(str[i])] == NULL) p->next[code(str[i])] = getNewNode();
        p = p->next[code(str[i])];
    }
    p->flag = 1;
    return;
}
int query(Node *root, char *str) {
    Node *p = root;
    for (int i= 0; str[i]; i++) {
        p = p->next[code(str[i])];
        if (p ==NULL) return 0;//没有
    }
    return p->flag;//看是否独立成词
}

void output(Node *root, int k, char *buff) {
    //按照字典序输出
    if (root == NULL) return ;
    if (root->flag) printf("%s\n",buff);
    for (int i = 0; i < BASE; i++) {
        buff[k+1] = '\0';//防止递归的残留信息dd
        buff[k] = BASE_LETTER + i;//字符转换后，存放字符
        output(root->next[i], k + 1, buff);
    }
}

void clear(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int main() {
    char str[1000];
    int n;
    scanf("%d",&n);
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s",str);
        insert(root, str);
    }
    printf("All are these:\n");
    output(root, 0, str);
    while(~scanf("%s",str)) {
        int ans  = query(root, str);
        if (ans) {
            printf("There have\n");
        } else {
            printf("No this sentence\n");
        }
    }

    return 0;
}
