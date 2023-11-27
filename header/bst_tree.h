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
  NodePtr<T> IsKey(T item);
  int findDepthByValue(T item);
  T minimum(T item);
  T maximum(T item);
  NodePtr<T> getRoot();
  virtual NodePtr<T> recursiveInsert(NodePtr<T> node, T item);
  int insert(T item);
  int getHeight(NodePtr<T> current_node);

  int countNodesSmallerThan(NodePtr<T> root, int target);
  int rank(NodePtr<T> root, int target);

  // + Implementation required...

 protected:
  // pointer of root node
  NodePtr<T> root_;
  // total size of BST
  int size_;
};

#endif  // BSTTREE_H_