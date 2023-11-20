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
};