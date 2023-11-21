#include "../header/avl_tree.h"
#include "../header/bst_tree.h"

using namespace std;

// 생성자의 정의
template <typename T>
AVLTree<T>::AVLTree() : BinarySearchTree<T>() {
  std::cout << "avl tree 생성자 호출" << std::endl;
}

// avlMemberGetter 함수의 정의
template <typename T>
NodePtr<T> AVLTree<T>::Insert(NodePtr<T>& r, int item) {
  NodePtr<T> z = new Node<T>;
  z->key = item;
  r = z;
  return r;
}