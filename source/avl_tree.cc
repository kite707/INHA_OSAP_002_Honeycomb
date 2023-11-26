#include "../header/avl_tree.h"
#include "../header/bst_tree.h"
#include "algorithm"
using namespace std;

// 생성자
template <typename T>
AVLTree<T>::AVLTree() : BinarySearchTree<T>(){};  // 자동 초기화

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
    std::cout << item << " is already exists\n";
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
// centor_node를 중심으로 왼쪽으로 회전
template <typename T>
NodePtr<T> AVLTree<T>::rotateLeft(NodePtr<T> centor_node) {
  NodePtr<T> parent_node = centor_node->right;
  centor_node->right = parent_node->left;
  parent_node->left = centor_node;

  // centor_node와 parent_node 위치 재조정
  //  bst 에서 높이를 받는 함수생성 후 대체 가능
  centor_node->height = std::max(this->getHeight(centor_node->left),
                                 this->getHeight(centor_node->right)) +
                        1;
  parent_node->height = std::max(this->getHeight(parent_node->left),
                                 this->getHeight(parent_node->right)) +
                        1;

  return parent_node;
}

// RotateRight 함수
// centor_node를 중심으로 오른쪽으로 회전
template <typename T>
NodePtr<T> AVLTree<T>::rotateRight(NodePtr<T> centor_node) {
  NodePtr<T> parent_node = centor_node->left;
  centor_node->left = parent_node->right;
  parent_node->right = centor_node;

  // centor_node와 parent_node 위치 재조정
  //  bst 에서 높이를 받는 함수생성 후 대체 가능
  centor_node->height = std::max(this->getHeight(centor_node->left),
                                 this->getHeight(centor_node->right)) +
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

/* erase: 노드 삭제 후 depth 반환하기 */
template <typename T>
int AVLTree<T>::erase(const T& key) {
  NodePtr<T> node = this->IsKey(key);
  if (node != nullptr) {
    int depth = this->findDepthByValue(key);
    eraseNode(this->root_, key);
    this->size_ = this->size_ - 1;
    return depth;
  } else {
    return 0;
  }
}

/* eraseNode: 실질적인 노드 삭제 수행 */
template <typename T>
void AVLTree<T>::eraseNode(NodePtr<T>& root, const T& key) {
  if (root == nullptr) {
    return;  // 비어 있다면 넘기기
  }

  if (key < root->key) {
    eraseNode(root->left, key);
  } else if (key > root->key) {
    eraseNode(root->right, key);
  } else {
    if (root->left == nullptr) {
      transplant(root->right);
    } else if (root->right == nullptr) {
      transplant(root->left);
    } else {
      NodePtr<T> successor = findSuccessor(root->right);
      root->key = successor->key;
      eraseNode(root->right, successor->key);
    }

    root->height =
        1 + max(this->getHeight(root->left), this->getHeight(root->right));
  }
}

/* Transplant: 자식 노드 이식 함수 */
template <typename T>
void AVLTree<T>::transplant(NodePtr<T>& x) {
  NodePtr<T> y = x;  // 노드 삭제를 위해 y 사용

  if (x->left == nullptr) {
    x = x->right;
  } else if (x->right == nullptr) {
    x = x->left;
  } else {
    NodePtr<T> z = x->right;  // z : 삭제할 x의 다음으로 가장 작은 수
    NodePtr<T> pZ = x;        // p[z] : z의 부모 노드

    /* 오른쪽 자식중 가장 작은 값 찾기*/
    while (z->left != nullptr) {
      pZ = z;
      z = z->left;
    }

    x->key = z->key;  // successor과 key값 교환

    /* 오른쪽 자식이 가장 작다면 */
    if (pZ == x) {
      pZ->right = z->right;  // z의 오른쪽 자식 붙여주기
    } else {
      pZ->left = z->right;  // 오른쪽 자식의 왼쪽 자식이 있다면
    }  // 그 z(successor)의 오른쪽 자식 p[z]의 왼쪽에 붙여주기

    // 이식 후 높이 업데이트
    pZ->height = 1 + max(this->getHeight(pZ->left), this->getHeight(pZ->right));
    x = pZ;

    delete y;  // 메모리 해제
  }
}

/* findSuccessor: 후임자 찾기 역할 */
template <typename T>
NodePtr<T> AVLTree<T>::findSuccessor(const NodePtr<T>& node) {
  NodePtr<T> current = node;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}