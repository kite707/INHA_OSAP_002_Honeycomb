#include "../header/bst_tree.h"
#include <iostream>

using namespace std;

/* Constructor */
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr), size_(0) {}

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

/* find max */
template <typename T>
void BinarySearchTree<T>::maximum(int item) {
  NodePtr<T> x = IsKey(item);
  while (x->right != nullptr) {
    x = x->right;
  }
  cout << x->key << " " << findDepthByValue(x->key) << "\n";
}

/* find min */
template <typename T>
void BinarySearchTree<T>::minimum(int item) {
  NodePtr<T> x = IsKey(item);
  while (x->left != nullptr) {
    x = x->left;
  }
  cout << x->key << " " << findDepthByValue(x->key) << "\n";
}

/* Return a root of tree*/
template <typename T>
NodePtr<T> BinarySearchTree<T>::getRoot() {
  return this->root_;
}

/* insert a node in bst tree*/
template <typename T>
NodePtr<T> BinarySearchTree<T>::insert(NodePtr<T> node, int item) {
  if (node == nullptr) {
    NodePtr<T> z = new Node<T>;
    z->key = item;
    node = z;
    return node;
  } else if (node->key < item) {
    node->right = insert(node->right, item);
  } else {
    node->left = insert(node->left, item);
  }
  return node;
}

/* insert helper function to use in main.cc*/
template <typename T>
void BinarySearchTree<T>::Insert_helper(int item) {
  if (IsKey(item)) {
    cout << item << " is already exists\n";
    return;
  }
  this->root_ = insert(this->root_, item);
  this->size_ = this->size_ + 1;
  return;
}