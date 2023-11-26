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
NodePtr<T> BinarySearchTree<T>::IsKey(int item) {
  NodePtr<T> t = this->root_;

  /*key값을 찾거나 없다면 break*/
  while (t != nullptr && t->key != item) {
    t = (item < t->key) ? t->left : t->right;
  }
  return t;
}

/* Return depth of the node with item as key */
template <typename T>
int BinarySearchTree<T>::findDepthByValue(int item) {
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
T BinarySearchTree<T>::minimum(int item) {
  NodePtr<T> x = IsKey(item);
  while (x->left != nullptr) {
    x = x->left;
  }
  cout << x->key << " " << findDepthByValue(x->key) << "\n";
  return x->key;  // 최솟값 출력 뿐만 아니라 값을 리턴하도록 수정
}

/* find max */
template <typename T>
T BinarySearchTree<T>::maximum(int item) {
  NodePtr<T> x = IsKey(item);
  if (x == nullptr) {
    return T{};
  }
  while (x->right != nullptr) {
    x = x->right;
  }
  cout << x->key << " " << findDepthByValue(x->key) << "\n";
  return x->key;
}

/* Return a root of tree*/
template <typename T>
NodePtr<T> BinarySearchTree<T>::getRoot() {
  return this->root_;
}

/* insert helper function to use in main.cc*/
template <typename T>
int BinarySearchTree<T>::insert(int item) {
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
NodePtr<T> BinarySearchTree<T>::recursiveInsert(NodePtr<T> node, int item) {
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