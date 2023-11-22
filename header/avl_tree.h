#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <iostream>
#include "bst_tree.h"

/* AVL Tree Class */
template <typename T>
class AVLTree : public BinarySearchTree<T> {
 public:
  AVLTree();
  NodePtr<T> Insert(NodePtr<T>& r, int item);
  int getBalanceFactor(NodePtr<T>& r);
  // NodePtr RotateLeft(NodePtr<T>& x);
  // NodePtr RotateRight(NodePtr<T>& y);
  // void Balancing(NodePtr<T>& r, int item);

 private:
};

#endif
