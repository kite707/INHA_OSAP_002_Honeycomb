#include "../header/avlTree.h"

using namespace std;

// 생성자의 정의
template <typename T>
AVLTree<T>::AVLTree() : BinarySearchTree<T>(), avlMember(0) {
  std::cout << "avl tree 생성자 호출" << std::endl;
}

// avlMemberGetter 함수의 정의
template <typename T>
T AVLTree<T>::avlMemberGetter() {
  return avlMember;
}