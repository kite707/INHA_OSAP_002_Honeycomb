#ifndef BSTTREE_H_
#define BSTTREE_H_

#include "tree_node.h"

template <typename T>
using NodePtr = Node<T>*;

/* BST Class */
template <typename T>
class BinarySearchTree {
 public:
  BinarySearchTree();
  int getSize();
  void addSize();
  bool isEmpty();
  NodePtr<T> IsKey(int item);
  int findDepthByValue(int item);
  T minimum(int item);
  T maximum(int item);
  NodePtr<T> getRoot();
  virtual NodePtr<T> recursiveInsert(NodePtr<T> node, int item);
  int insert(int item);
  int getHeight(NodePtr<T> current_node);
  // + Implementation required...

 protected:
  // pointer of root node
  NodePtr<T> root_;
  // total size of BST
  int size_;
};

#endif  // BSTTREE_H_