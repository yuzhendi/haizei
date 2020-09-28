/*************************************************************************
	> File Name: 1RBT.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月16日 星期六 15时05分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* ************有 BUG  *******/

#define RED 0
#define BLACK 1
#define DBLACK 2

typedef struct Node {
    int key;
    int color; // 0 red, 1 black, 2 double black
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor)) //先于主函数执行
void init_NIL() {//初始化NIL节点
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL;
    NIL->color = BLACK;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = RED;
    return p;
}

bool has_red_child(Node *root) {//判断孩子节点中是否有红色， 有则 返回 1
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

Node *insert_maintain(Node *root) {//插入调整
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        //左右子孩子都是红色节点
        root->color = RED;
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    if (root->lchild->color == RED) {//左孩子是红色
        if (!has_red_child(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {//右孩子是红色
        if (!has_red_child(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    root->color = RED;//红色上顶
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}
Node *predeccessor(Node *root) {
    Node *temp = root->lchild;
    while(temp->rchild != NIL) {
        temp = temp->rchild;
    }
    return temp;
}
Node *erase_maintain(Node *root) {//目的是干掉双重黑节点
    if (root->lchild->color != DBLACK && root->rchild->color != DBLACK) 
        return root;
    if (has_red_child(root)) { // 最简单的情况， 直接删除红色的时候
        root->color = RED;//原来的变成red
        if (root->lchild->color == RED) {
            root = right_rotate(root);
            root =  erase_maintain(root->rchild);//递归调整
        } else {
            root = left_rotate(root);
            root = erase_maintain(root->lchild);
        }
        root->color = BLACK;//新的根结点变成黑色
        return root;
    }
    /*  情况1   */
    if ((root->lchild->color == DBLACK && !has_red_child(root->rchild)) ||
        (root->rchild->color == DBLACK && !has_red_child(root->lchild))) {
            root->color +=1 ;
            root->lchild -= 1;
            root->rchild -= 1;
            return root;
        }
    
    if (root->rchild->color == BLACK) {
        /*    情况 2  */
        if (root->rchild->rchild != RED) {//RL 情况2
            root->rchild->color = RED;//72 变红
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;// 51 变黑
        }    //情况3
        root->rchild->color = root->color;// 51 改成 38 的颜色
        root->color = BLACK;// 38 改称黑色
        root->lchild->color -= 1;// x 减一重黑
        root = left_rotate(root);
        root->rchild->color = BLACK;// 72 改成 黑色
    } else {//对陈修改
        if (root->lchild->lchild != RED) {
            root->lchild->color = RED;
            root->lchild = right_rotate(root->lchild);
            root->lchild->color = BLACK;
        }    
        root->lchild->color = root->color;
        root->color = BLACK;
        root->rchild->color -= 1;
        root = right_rotate(root);
        root->lchild->color = BLACK;
        
    }
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;//返回唯一子孩子
        } else {
            Node *temp = predeccessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}


Node *__insert(Node *root, int key) {//找到合适的位值插入
    if (root == NIL) return getNewNode(key);
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
    if (root == NIL) return ;
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
            case 1:  root = erase(root, val); break;
        }
        output(root);
    }
    return 0;
}
