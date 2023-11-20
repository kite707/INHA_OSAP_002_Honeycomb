#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <iostream>
#include "bstTree.h"
/* AVL Tree Class */
// 한글 주석 테스트
template <typename T>
class AVLTree : public BinarySearchTree<T> {
 public:
  AVLTree();
  T avlMemberGetter();

 private:
  T avlMember;
};

#endif