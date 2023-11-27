#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <algorithm>
#include "bst_tree.h"

/* AVL Tree Class */
template <typename T>
class AVLTree : public BinarySearchTree<T> {
 public:
  AVLTree();
  NodePtr<T> recursiveInsert(NodePtr<T> current_node, int item) override;
  int insert(int item);
  int getBalanceFactor(NodePtr<T> current_node);

 protected:
  // 가운데 노드 기준 왼쪽 회전
  NodePtr<T> rotateLeft(NodePtr<T> centor_node);
  // 가운데 노드 기준 오른쪽 회전
  NodePtr<T> rotateRight(NodePtr<T> center_node);
  // 현재 노드의 밸런스 확인 후, 필요하면 rotate를 이용하여 밸런스 조절
  void balancing(NodePtr<T>& current_node, int item);
};

#endif
