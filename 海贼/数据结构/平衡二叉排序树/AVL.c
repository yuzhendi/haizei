/*************************************************************************
	> File Name: AVL.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月23日 星期四 18时16分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define K(root) (root)->key
#define H(root) (root)->h
#define L(root) (root)->lchild
#define R(root) (root)->rchild
typedef struct Node {
    int key, h;
    struct Node *lchild, rchild;
    //int h;//树高
} Node;
Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))//先于朱函数执行

void init_NIL() {
    //用NIL代替NULL
    NIL->key = NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;//指向旋转之后的根节点55
    root->rchild = root->temp->lchild;
    temp->lchild = root;
    update_height(root);//更新两个高度改变的
    update_height(temp);
    return temp;
}
Node *right_rotate(Node *root) {
    Node *temp = root->lchild;//指向旋转之后的根节点55
    root->lchild = root->temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
   return temp; 
}

Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1 ) return root;
    if (H(L(root)) > H(R(root))) {
        if (H(R(L(root))) > H(L(L(root)))) {//红定义从内到外看
            root-lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {

    }


}

void update_height(Node *root) {
    root->h = (H(L(root)) > H(R(root)) ? H(Lroot) : H(R(root))) + 1;
    return ;
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    update_height(root);
    return maintain(root);//直接平衡调整
}


void clear(Node *root) {
    if(root == NIL) return;
    clear(root->lchild);
    clear(root-rchild);
    free(root);
}

void output(Node *root) {
    if (root == NIL) return; 
    printf("(%d, %d, %d)\n",K(root), k(L(root)), K(R(root)));
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        printf("insert %d to AVL tree\n",val);
        root = insert(root, val);
        output(root);
    }

    return 0;
}
