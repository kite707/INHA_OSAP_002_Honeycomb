#include "../header/avl_tree.h"
#include "../header/bst_tree.h"

// 생성자
template <typename T>
AVLTree<T>::AVLTree() : BinarySearchTree<T>() {
  std::cout << "avl tree 생성자 호출" << std::endl;
}

// Insert 함수
template <typename T>
NodePtr<T> AVLTree<T>::Insert(NodePtr<T>& r, int item) {
  if (r == nullptr) {
    NodePtr<T> z = new Node<T>;
    z->key = item;
    r = z;
    return r;
  } else if (r->key < item) {
    r->right = Insert(r->right, item);
  } else {
    r->left = Insert(r->left, item);
  }
  // 높이 구하는 함수 구현 필요
  // 밸런싱 함수 구현 필요
  return r;
}