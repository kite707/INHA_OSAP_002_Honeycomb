#include "../header/avl_tree.h"
#include "../header/bst_tree.h"
// 생성자
template <typename T>
AVLTree<T>::AVLTree() : BinarySearchTree<T>() {}

// Insert 함수
template <typename T>
NodePtr<T> AVLTree<T>::recursiveInsert(NodePtr<T> current_node, int item) {
  // leafnode에 도달시 새로운 노드 삽입
  if (current_node == nullptr) {
    NodePtr<T> new_node = new Node<T>;
    new_node->key = item;
    current_node = new_node;
    this->root_ = current_node;
    return current_node;
  }
  // 현재 노드의 key값보다 새로 삽입할 노드의 key값이 더 크다면
  // 현재 노드의 오른쪽 자식으로 insert 함수 재귀 호출
  else if (current_node->key < item) {
    current_node->right = recursiveInsert(current_node->right, item);
  }
  // 현재 노드의 key값보다 새로 삽입할 노드의 key값이 더 작다면
  // 현재 노드의 왼쪽 자식으로 insert 함수 재귀 호출
  else {
    current_node->left = recursiveInsert(current_node->left, item);
  }
  // 높이 구하기
  current_node->height = std::max(this->getHeight(current_node->left),
                                  this->getHeight(current_node->right)) +
                         1;
  // 밸런싱 함수 구현
  balancing(current_node, item);
  this->root_ = current_node;
  return current_node;
}
// 값 insert 후 depth리턴하는 함수
template <typename T>
int AVLTree<T>::insert(int item) {
  if (this->IsKey(item)) {
    return -1;
  }
  this->root_ = recursiveInsert(this->root_, item);
  this->size_ = this->size_ + 1;
  return this->findDepthByValue(item);
}

// balancefactor 받아오는 함수
// 왼쪽 자식과 오른쪽 자식의 차이를 반환
// getHeight() 함수를 구현하면 대체
template <typename T>
int AVLTree<T>::getBalanceFactor(NodePtr<T> current_node) {
  return this->getHeight(current_node->left) -
         this->getHeight(current_node->right);
}

// RotateLeft 함수
// center_node를 중심으로 왼쪽으로 회전
template <typename T>
NodePtr<T> AVLTree<T>::rotateLeft(NodePtr<T> center_node) {
  NodePtr<T> parent_node = center_node->right;
  center_node->right = parent_node->left;
  parent_node->left = center_node;

  // center_node와 parent_node 위치 재조정
  //  bst 에서 높이를 받는 함수생성 후 대체 가능
  center_node->height = std::max(this->getHeight(center_node->left),
                                 this->getHeight(center_node->right)) +
                        1;
  parent_node->height = std::max(this->getHeight(parent_node->left),
                                 this->getHeight(parent_node->right)) +
                        1;

  return parent_node;
}

// RotateRight 함수
// center_node를 중심으로 오른쪽으로 회전
template <typename T>
NodePtr<T> AVLTree<T>::rotateRight(NodePtr<T> center_node) {
  NodePtr<T> parent_node = center_node->left;
  center_node->left = parent_node->right;
  parent_node->right = center_node;

  // center_node와 parent_node 위치 재조정
  //  bst 에서 높이를 받는 함수생성 후 대체 가능
  center_node->height = std::max(this->getHeight(center_node->left),
                                 this->getHeight(center_node->right)) +
                        1;
  parent_node->height = std::max(this->getHeight(parent_node->left),
                                 this->getHeight(parent_node->right)) +
                        1;

  return parent_node;
}

// Balancing 함수
// insert에서 재귀적으로 돌면서 밸런스가 깨진 노드들 밸런스 다시 맞춤
template <typename T>
void AVLTree<T>::balancing(NodePtr<T>& current_node, int item) {
  int balance_factor = getBalanceFactor(current_node);

  // LL
  if (balance_factor > 1 && item < current_node->left->key) {
    current_node = rotateRight(current_node);
  }
  // LR
  else if (balance_factor > 1 && item > current_node->left->key) {
    current_node->left = rotateLeft(current_node->left);
    current_node = rotateRight(current_node);
  }
  // RR
  else if (balance_factor < -1 && item > current_node->right->key) {
    current_node = rotateLeft(current_node);
  }
  // RL
  else if (balance_factor < -1 && item < current_node->right->key) {
    current_node->right = rotateRight(current_node->right);
    current_node = rotateLeft(current_node);
  }
}
