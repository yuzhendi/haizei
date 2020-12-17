/*************************************************************************
	> File Name: AVL.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月17日 星期四 10时54分18秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int key, h; //值和树高
    struct Node* lchild, *rchild;
}Node;

Node _NIL, *NIL = &_NIL;
__attribute__((constructor)) // 加上此关键字，先于主函数执行
void init_NIL() {
    NIL->key = 0;
    NIL->h = 0;
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
void UpdateHeight(Node *root) {
    int h1 = root->lchild->h; // 加入NIL节点后，没有空节点
    int h2 = root->rchild->h;
    root->lchild ->h= (h1 > h2 ? h1 : h2) + 1;
}
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;// 旋转完之后的根结点
    root->rchild = temp->lchild;
    temp->lchild = root;
    UpdateHeight(root); // 更新老的节点操作
    UpdateHeight(temp); // 更新新的节点操作
    return temp;
}
Node *right_rotate(Node *root) {
    Node *temp = root->lchild;// 旋转完之后的根结点
    root->lchild = temp->rchild;
    temp->rchild = root;
    UpdateHeight(root); // 更新老的节点操作
    UpdateHeight(temp); // 更新新的节点操作
    return temp;
}


Node *maintain(Node *root) {
    if (abs(root->lchild->h - root->rchild->h) <= 1) return root;
    // LL类型
    if (root->lchild->h > root->rchild->h) {
        if (root->lchild->rchild->h > root->lchild->lchild->h) {
            root->lchild = left_rotate(root->lchild);// LR类型
        }
        root = right_rotate(root); //大右旋
    } else {
        if (root->rchild->lchild->h > root->rchild->rchild->h) {
            root->rchild = left_rotate(root->rchild);// RL类型
        }
        root = left_rotate(root); // 大左旋
    }
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    UpdateHeight(root); // 更新树高
    return maintain(root);
}
Node *predeccessor(Node *root) { // 找到前驱节点
    Node *temp = root->lchild;
    while(temp->rchild != NIL) temp = temp->rchild;
    return temp;
}


Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) {
        root->lchild = erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) { //删除度为0或1的节点
            Node *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            free(root);
            return temp;
            } else { // 度为2的节点
                Node *temp = predeccessor(root); // 找到前驱节点，，转换成度为1的节点
                root->key = temp->key;
                    root->lchild = erase(root->lchild, temp->key);
                
            }
    }
    UpdateHeight(root);
    return maintain(root);
}


void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}



int main() {


    return 0;
}
