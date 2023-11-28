#include "../header/bst_tree2.h"
#include <algorithm>
#include <iostream>

using namespace std;

/* Constructor */
template <typename T>
BinarySearchTree2<T>::BinarySearchTree2() : root_(nullptr), size_(0){};

/* Return size of BST */
template <typename T>
int BinarySearchTree2<T>::getSize() {
  return this->size_;
}
