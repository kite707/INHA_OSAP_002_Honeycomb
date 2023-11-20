#include "../header/bstTree.h"

using namespace std;

/* constructor */
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {}

/* class member func */
template <typename T>
int BinarySearchTree<T>::getSize() {
  return size;
}

template <typename T>
void BinarySearchTree<T>::addSize() {
  this->size += 1;
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() {
  return root == nullptr;
}

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

template <typename T>
int BinarySearchTree<T>::findDepthByValue(int item) {
  if (!IsKey(item)) {
    return 0;
  }
  NodePtr t = root;
  int depth = 0;

  while (t != nullptr && t->key != item) {
    t = (item < t->key) ? t->left : t->right;
    depth++;
  }

  return depth;
}