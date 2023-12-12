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
  void setRoot(const NodePtr<T>& node);

 protected:
  // pointer of root node
  NodePtr<T> root_;
  // total size of BST
  int size_;
};

#endif  // BSTTREE_H_