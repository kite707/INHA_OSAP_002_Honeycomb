// MIT License

// Copyright(c) 2023 HONEYCOMB

//     Permission is hereby granted,
//     free of charge,
//     to any person obtaining a copy of this software and associated
//     documentation files(the "Software"), to deal in the Software without
//     restriction, including without limitation the rights to use, copy,
//     modify, merge, publish
//     ,
//     distribute, sublicense, and / or sell copies of the Software,
//     and to permit persons to whom the Software is furnished to do so,
//     subject to the following conditions :

//     The above copyright notice and this permission notice shall be included
//     in all copies or substantial portions of the Software.

//     THE SOFTWARE IS PROVIDED "AS IS",
//     WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
//     INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
//     THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//     OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//     OTHER DEALINGS IN THE SOFTWARE.
//
//     2023.11 HONEYCOMB

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <algorithm>
#include "adaptor.h"
#include "bst_tree.h"

/* AVL Tree Class */
template <typename T>
class AVLTree : public virtual Adaptor<T>, public virtual BinarySearchTree<T> {
 public:
  AVLTree();
  NodePtr<T> recursiveInsert(NodePtr<T> current_node, T item) override;
  int insert(T item) override;
  int getBalanceFactor(NodePtr<T> current_node);
  int erase(const T& key) override;
  void eraseNode(NodePtr<T>& root, const T& key);
  void transplant(NodePtr<T>& x);
  NodePtr<T> findSuccessor(const NodePtr<T>& node);
  int find(int item) override {
    return BinarySearchTree<T>::findDepthByValue(item);
  };
  int rank(T target) override {
    return BinarySearchTree<T>::rank(this->getRoot(), target);
  }
  T minimum(T item) override { return BinarySearchTree<T>::minimum(item); }
  T maximum(T item) override { return BinarySearchTree<T>::maximum(item); }
  int size() override { return BinarySearchTree<T>::getSize(); }
  bool empty() override { return BinarySearchTree<T>::isEmpty(); }
  // 가운데 노드 기준 왼쪽 회전
  NodePtr<T> rotateLeft(NodePtr<T> center_node);
  // 가운데 노드 기준 오른쪽 회전
  NodePtr<T> rotateRight(NodePtr<T> center_node);

 protected:
  // 현재 노드의 밸런스 확인 후, 필요하면 rotate를 이용하여 밸런스 조절
  void balancing(NodePtr<T>& current_node, T item);
};

#endif
