/*************************************************************************
	> File Name: RBT_Hug.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月25日 星期一 10时36分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef struct Node {
    int key, color; // 0 red, 1 black, 2 double black
    struct Node *lchild, *rchild;
} Node;

Node _NIL, * const NIL = &_NIL;//指向本身，指针里的指向不能变

__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL;
    NIL->color = BLACK;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;//叶子节点是黑色
    p->color = RED;
    return p;
}

int hasRedChild(Node *root) {//判断是否有红色子树节点
    return root->lchild->color == RED || root->rchild->color == RED;
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
    if (!hasRedChild(root)) return root;//没有red子孩子，直接返回
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!hasRedChild(root->lchild) && !hasRedChild(root->rchild)) return root;
        goto insert_end;
    }
    if (root->lchild->color == RED) {
        if (!hasRedChild(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (!hasRedChild(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
insert_end:
    root->color = RED;//红色上浮
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

Node *predeccessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {//删除调整（站在父节点看）
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root;// root的孩子没有double BLACK
    if (root->rchild->color == DOUBLE_BLACK) {//右孩子是double BLACK
        if (root->lchild->color == RED) {
            root->color = RED;
            root->lchild->color = BLACK;
            root = right_rotate(root);
            root->rchild = erase_maintain(root->rchild);
            return root;
        }
        if (!hasRedChild(root->lchild)) {
            root->color += 1;
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            return root;
        }
        if (root->lchild->lchild->color != RED) {//LR类型
            root->lchild->rchild->color = BLACK;
            root->lchild->color = RED;
            root->lchild = left_rotate(root->lchild);
        }
        root->lchild->color = root->color;
        root->rchild->color -= 1;
        root = right_rotate(root);
        root->lchild->color = root->rchild->color = BLACK;
    } else {
        if (root->rchild->color == RED) {//兄弟子树是red的时候（转移到根结点）
            root->color = RED;//原来的变成red
            root->rchild->color = BLACK;//新的根结点变成黑色
            root = left_rotate(root);
            root->lchild = erase_maintain(root->lchild);//递归操作
            return root;
        }
        if (!hasRedChild(root->rchild)) {//兄弟子树下没有red
            root->color += 1;
            root->lchild->color -= 1;//去掉 DOUBLE_BLACK
            root->rchild->color -= 1;
            return root;
        }
        if (root->rchild->rchild->color != RED) {
            root->rchild->lchild->color = BLACK;
            root->rchild->color = RED;
            root->rchild = right_rotate(root->rchild);
        }
        root->rchild->color = root->color;
        root->lchild->color -= 1;
        root = left_rotate(root);
        root->lchild->color = root->rchild->color = BLACK;
    }
    return root;
}

Node *__erase(Node *root, int key) {//删除操作
    if (root == NIL) return root;
    if (root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {//删除时度为1 或 0 的情况
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;// 将当前节点的颜色加到唯一子孩子上面（对NIL也适用）
            free(root);
            return temp;
        } else {
            Node *temp = predeccessor(root);//度为2 的时候
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);//转化为在左子树删除 temp->key
        }
    }
    return erase_maintain(root);//回溯的时候进行平衡调整
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
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
    if (root == NIL) return ;
    output(root->lchild);
    printf("%d %d %d %d\n",root->key,root->color, root->lchild->key,root->rchild->key);
    /*printf("%d [%d, %d] %s\n", 
        root->key, 
        root->lchild->key, 
        root->rchild->key,
        root->color ? "BLACK" : "RED"
    );*/
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            case 3: output(root);break;
        }
        //output(root);
    }
    return 0;
}
