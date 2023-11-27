#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <algorithm>
#include "adaptor.h"
#include "bst_tree.h"

/* AVL Tree Class */
template <typename T>
class AVLTree : public virtual BinarySearchTree<T>, public virtual Adaptor<T> {
 public:
  AVLTree();
  NodePtr<T> recursiveInsert(NodePtr<T> current_node, T item) override;
  int insert(T item) override;
  int getBalanceFactor(NodePtr<T> current_node);
  int find(int item) override {
    return BinarySearchTree<T>::findDepthByValue(item);
  };
  T minimum(T item) override { return BinarySearchTree<T>::minimum(item); }
  T maximum(T item) override { return BinarySearchTree<T>::maximum(item); }
  int size() override { return BinarySearchTree<T>::getSize(); }
  bool empty() override { return BinarySearchTree<T>::isEmpty(); };

 protected:
  // 가운데 노드 기준 왼쪽 회전
  NodePtr<T> rotateLeft(NodePtr<T> center_node);
  // 가운데 노드 기준 오른쪽 회전
  NodePtr<T> rotateRight(NodePtr<T> center_node);
  // 현재 노드의 밸런스 확인 후, 필요하면 rotate를 이용하여 밸런스 조절
  void balancing(NodePtr<T>& current_node, T item);
};

#endif
