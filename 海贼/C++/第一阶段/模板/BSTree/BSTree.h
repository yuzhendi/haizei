/*************************************************************************
	> File Name: BSTree.h
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月14日 星期五 12时37分01秒
 ************************************************************************/

#ifndef _BSTREE_H
#define _BSTREE_H
#include <shared_ptr>
namespace haizei{
template<typename T>
struct BsNode{
    BsNode(const T &data) : data(data), lchild(nullptr), rchild(nullptr){}
    T data;
    shared_ptr<BsNode> *lchild, *rchild;
};

template<typename T>
struct BSTree {

private:

};


}
#endif
