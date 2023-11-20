#include "../header/bstTree.h"

using namespace std;

/* Constructor */
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {}

/* Return size of BST */
template <typename T>
int BinarySearchTree<T>::get_size() {
  return size;
}

/* Increase size of BST */
template <typename T>
void BinarySearchTree<T>::set_size_plus() {
  this->size += 1;
}

/* Return true if BST is empty */
template <typename T>
bool BinarySearchTree<T>::isEmpty() {
  return root == nullptr;
}

/* Return true if any node has item as key value */
template <typename T>
bool BinarySearchTree<T>::IsKey(int item) {
  NodePtr t = root;
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
  NodePtr t = root;
  int depth = 0;

  // Break if key value is found or not found
  while (t != nullptr && t->key != item) {
    t = (item < t->key) ? t->left : t->right;
    depth++;
  }

  return depth;
}