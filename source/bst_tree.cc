#include "../header/bst_tree.h"

using namespace std;

/* Constructor */
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) {}

/* Return size of BST */
template <typename T>
int BinarySearchTree<T>::getSize() {
  return size_;
}

/* Increase size of BST */
template <typename T>
void BinarySearchTree<T>::addSize() {
  this->size_ += 1;
}

/* Return true if BST is empty */
template <typename T>
bool BinarySearchTree<T>::isEmpty() {
  return root_ == nullptr;
}

/* Return true if any node has item as key value */
template <typename T>
bool BinarySearchTree<T>::IsKey(int item) {
  NodePtr<T> t = this->root_;
  if (isEmpty()) {
    return false;
  } else {
    while (t != nullptr && t->key != item) {
      t = (item < t->key) ? t->left : t->right;
    }
    return true;
  }
}

/* Return depth of the node with item as key */
template <typename T>
int BinarySearchTree<T>::findDepthByValue(int item) {
  if (!IsKey(item)) {
    return 0;
  }
  NodePtr<int> t = root_;
  int depth = 0;

  // Break if key value is found or not found
  while (t != nullptr && t->key != item) {
    t = (item < t->key) ? t->left : t->right;
    depth++;
  }

  return depth;
}