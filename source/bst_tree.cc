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

#include "../header/bst_tree.h"
#include <algorithm>
#include <iostream>

using namespace std;

/* Constructor */
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr), size_(0){};

/* Return size of BST */
template <typename T>
int BinarySearchTree<T>::getSize() {
  return this->size_;
}

/* Increase size of BST */
template <typename T>
void BinarySearchTree<T>::addSize() {
  this->size_ += 1;
}

/* Return true if BST is empty */
template <typename T>
bool BinarySearchTree<T>::isEmpty() {
  return this->root_ == nullptr;
}

/* Return true if any node has item as key value */
template <typename T>
NodePtr<T> BinarySearchTree<T>::IsKey(T item) {
  NodePtr<T> t = this->root_;

  /*key값을 찾거나 없다면 break*/
  while (t != nullptr && t->key != item) {
    t = (item < t->key) ? t->left : t->right;
  }
  return t;
}

/* Return depth of the node with item as key */
template <typename T>
int BinarySearchTree<T>::findDepthByValue(T item) {
  if (!IsKey(item)) {
    return 0;
  }
  NodePtr<T> t = this->root_;
  int depth = 0;

  /*key값을 찾거나 없다면 break*/
  while (t != nullptr && t->key != item) {
    t = (item < t->key) ? t->left : t->right;
    depth++;
  }
  return depth;
}

/* find min: item보다 작은 값 중 가장 작은 값을 리턴 */
template <typename T>
T BinarySearchTree<T>::minimum(T item) {
  NodePtr<T> x = IsKey(item);
  while (x->left != nullptr) {
    x = x->left;
  }
  return x->key;
}

/* find max */
template <typename T>
T BinarySearchTree<T>::maximum(T item) {
  NodePtr<T> x = IsKey(item);
  if (x == nullptr) {
    return T{};
  }
  while (x->right != nullptr) {
    x = x->right;
  }
  return x->key;
}

/* Return a root of tree*/
template <typename T>
NodePtr<T> BinarySearchTree<T>::getRoot() {
  return this->root_;
}

/* insert helper function to use in main.cc*/
template <typename T>
int BinarySearchTree<T>::insert(T item) {
  if (IsKey(item)) {
    cout << item << " is already exists\n";
    return -1;
  }
  this->root_ = recursiveInsert(this->root_, item);
  this->size_ = this->size_ + 1;
  return this->findDepthByValue(item);
}

/* insert a node in bst tree*/
template <typename T>
NodePtr<T> BinarySearchTree<T>::recursiveInsert(NodePtr<T> node, T item) {
  if (node == nullptr) {
    NodePtr<T> z = new Node<T>;
    z->key = item;
    return z;
  } else if (node->key < item) {
    node->right = recursiveInsert(node->right, item);
  } else {
    node->left = recursiveInsert(node->left, item);
  }

  node->height =
      1 + max(getHeight(node->left), getHeight(node->right));  // 높이 업뎃
  return node;
}

template <typename T>
int BinarySearchTree<T>::getHeight(NodePtr<T> current_node) {
  if (current_node == nullptr)
    return 0;
  else
    return current_node->height;
}

template <typename T>
int BinarySearchTree<T>::countNodesSmallerThan(NodePtr<T> root, T target) {
  if (root == nullptr) {
    return 0;
  }

  if (target < root->key) {
    return countNodesSmallerThan(root->left, target);
  } else if (target > root->key) {
    // 현재 노드와 현재 노드의 왼쪽 서브트리에 있는 노드의 개수를 합산
    return 1 + countNodesSmallerThan(root->right, target) +
           countNodesSmallerThan(root->left, target);
  } else {
    // 현재 노드와 현재 노드의 왼쪽 서브트리에 있는 노드의 개수를 합산
    return countNodesSmallerThan(root->left, target);
  }
}

template <typename T>
int BinarySearchTree<T>::rank(NodePtr<T> root, T target) {
  return countNodesSmallerThan(root, target) + 1;
}

// countNodesSmallerThan 은 자신보다 낮은 노드 개수를 세주는 함수
// Rank는 자신보다 작은 노드 개수 + 1 = rank를 구하는 함수.

/* erase: 노드 삭제 후 depth 반환하기 */
template <typename T>
int BinarySearchTree<T>::erase(const T& key) {
  NodePtr<T> node = IsKey(key);
  if (node != nullptr) {
    int depth = this->findDepthByValue(key);
    eraseNode(this->root_, key);
    size_--;
    return depth;
  } else
    return 0;
}

/* eraseNode: 자식 이식 및 후임자를 활용한 실질적인 노드 삭제 수행 */
template <typename T>
void BinarySearchTree<T>::eraseNode(NodePtr<T>& root, const T& key) {
  if (root == nullptr) {
    return;  // 비어 있다면 넘기기
  }

  if (key < root->key) {
    eraseNode(root->left, key);
  } else if (key > root->key) {
    eraseNode(root->right, key);
  } else {
    if (root->left == nullptr) {
      transplant(root->right);
    } else if (root->right == nullptr) {
      transplant(root->left);
    } else {
      NodePtr<T> successor = findSuccessor(root->right);
      root->key = successor->key;
      eraseNode(root->right, successor->key);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  }
}

/* Transplant: 자식 노드 이식 함수 */
template <typename T>
void BinarySearchTree<T>::transplant(NodePtr<T>& x) {
  NodePtr<T> temp = x;  // 노드 삭제를 위해 y 사용

  if (x->left == nullptr) {
    x = x->right;
  } else if (x->right == nullptr) {
    x = x->left;
  } else {
    NodePtr<T> y = x->right;  // y : 삭제할 x의 다음으로 가장 작은 노드
    NodePtr<T> parent_y = x;  // y의 부모 노드

    /* 오른쪽 자식중 가장 작은 값 찾기*/
    while (y->left != nullptr) {
      parent_y = y;
      y = y->left;
    }

    x->key = y->key;  // 후임자과 key값 교환

    /* 오른쪽 자식이 가장 작다면 */
    if (parent_y == x) {
      parent_y->right = y->right;  // 오른쪽 자식 붙여주기
    } else {
      parent_y->left = y->right;  // 오른쪽 자식의 왼쪽 자식이 있다면
    }  // 그 후임자의 오른쪽 자식 parent_y의 왼쪽에 붙여주기

    // 이식 후 높이 업데이트
    parent_y->height =
        1 + max(getHeight(parent_y->left), getHeight(parent_y->right));
    x = parent_y;
  }

  // 메모리를 위해 임시변수 삭제
  delete temp;
}

/* findSuccessor: 후임자 찾기 역할 */
template <typename T>
NodePtr<T> BinarySearchTree<T>::findSuccessor(const NodePtr<T>& node) {
  NodePtr<T> current = node;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}
