/*************************************************************************
	> File Name: RBT.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月16日 星期六 14时28分15秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define RED 0
#define BLACK 1
#define DBALCK 2

typedef struct Node {
    int key;
    int color; // 0 red, 1 black, 2 double black
    struct Node *lchild, *rchild;
}Node;

Node __NIL;
#define NIL (&__NIL);

__attribute__((constructor))//先于主函数执行
void init_NIL() {
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL;
    NIL->color = BLACK;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = RED;//默认红色
    return p;
}

bool has_red_child(Node *root) {
    //判断孩子节点是否有红色子孩子  有则返回 1
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        root->color = RED;
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    if (root->lchild->color == RED) {
        if (!has_red_child(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (!has_red_child(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}


Node *__insert(root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;//根结点强制转换成黑色
    return root;
}


void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return;
    printf("(%d | %d, %d, %d)\n", 
          root->color,
          root->key,
          root->lchild->key,
          root->rchild->key
          );
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: root = insert(root, val); break;
            case 1: break;
        }
        output(root);
    }
    return 0;
}
