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
  int getHeight(NodePtr<T> current_node);
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
  int countNodesSmallerThan(NodePtr<T> root, T target);
  int rank(NodePtr<T> root, T target);
  int erase(const T& key);
  void eraseNode(NodePtr<T>& root, const T& key);
  void transplant(NodePtr<T>& x);
  NodePtr<T> findSuccessor(const NodePtr<T>& node);

 protected:
  // pointer of root node
  NodePtr<T> root_;
  // total size of BST
  int size_;
};

#endif  // BSTTREE_H_