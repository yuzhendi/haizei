/*************************************************************************
	> File Name: AVL_Hu.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月23日 星期四 18时51分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define H(root) (root)->h
#define K(root) (root)->key
#define L(root) (root)->lchild
#define R(root) (root)->rchild

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))//使得函数在朱函数之前执行
void init_NIL() {
    NIL->key = NIL->h = 0;//用NIL代替NULL，防止的空间错误，同时可以使用h=0
    NIL->lchild = NIL->rchild = NIL;
    return ;
}


Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

void update_height(Node *root) {
    //更新节点的高度
    root->h = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
    return ;
}

Node *left_rotate(Node *root) {
    //左旋
    Node *temp = root->rchild;//指向旋转后的根结点
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);//更新改变了的高度
    update_height(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *maintain(Node *root) {
    //对节点的判断及调整
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (H(L(root)) > H(R(root))) {
        if (H(R(L(root))) > H(L(L(root)))) {//宏定义从里到外
                //左右大于左左,即LR型
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (H(L(R(root))) > H(R(R(root)))) {
            //RL型
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    update_height(root);//更新节点的高度
    return maintain(root);//调整
}

Node *predeccessor(Node *root) {
    Node *temp = root->lchild;
    while(temp->rchild != NIL) {
        temp = temp->rchild;
    }
    return temp;
}
Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) {
        root->lchild = erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            return maintain(temp);
        } else {
            //度为2的时侯
            Node *temp = predeccessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);

        }
    }
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d, %d, %d)\n", K(root), K(L(root)), K(R(root)));
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    #define MAX_OP 20
    Node *root = NIL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100, op = rand() % 5;
        switch(op) {
            case 0:
            case 1:
            case 2:
            case 3: {
                printf("insert %d to AVL tree\n", val);
                root = insert(root, val);
            }break;
            case 4: {
                printf("erase %d from AVL tree\n",val);
               root= erase(root, root->key);
            }break;
        }
        output(root);
    }
    return 0;
}
