#ifndef BSTTREE_H_
#define BSTTREE_H_

#include "tree_node.h"

template <typename T>
using NodePtr = Node<T>*;

/* BST Class */
template <typename T>
class BinarySearchTree2 {
 public:
  BinarySearchTree2();
  int getSize();

 protected:
  // pointer of root node
  NodePtr<T> root_;
  // total size of BST
  int size_;
};

#endif  // BSTTREE_H_