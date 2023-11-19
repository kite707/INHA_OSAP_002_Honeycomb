#include "../header/avlTree.h"
#include "set.h"

#include <algorithm>

using namespace std;
int add(int a, int b) {
  return a + b;
}
NodePtr AVLtree::Insert(NodePtr r, int item){
  /*새로운 노드 삽입*/
  if (r == nullptr) {
    NodePtr z = new node;
    z->key = item;
    r = z;
    return r;
  } else if (r->key < item) {  //item이 key값보다 크다면 오른쪽으로 이동
    r->right = Insert(r->right, item);
  } else {  //item이 key값보다 작다면 왼쪽으로 이동
    r->left = Insert(r->left, item);
  }
  r->height = max(getHeight(r->left), getHeight(r->right)) + 1;
  Balancing(r, item);  //새로운 노드가 추가되었으므로 재귀적으로 부모노드들 높이 1증가 시켜주고
                             //Balace Factor 측정하여 2이상이라면 재조정함수
  return r;
}

NodePtr AVLtree::Delete(NodePtr r, int item) {
  if (r->key > item && r->left != nullptr) {
     r->left = Delete(r->left, item);
  } else if (r->key < item && r->right != nullptr) {
    r->right = Delete(r->right, item);
  } else if (r->key == item) {
    // Transplant(r);
  }
        /*root를 지운게 아니라면*/
  if (r != nullptr) {
    r->height = max(getHeight(r->left), getHeight(r->right)) + 1;
    Balancing(r, item);
  }

  return r;
}
void AVLtree::Balancing(NodePtr& r, int item) {
  int bF = getBalanceFactor(r);

  //case 1 (left left)
  if (bF > 1 && item < r->left->key) {
    r = RotateRight(r);
  }
  //case 2 (left right)
  else if (bF > 1 && item > r->left->key) {
    r->left = RotateLeft(r->left);
    r = RotateRight(r);
  }
  //case 3 (right right)
  else if (bF < -1 && item > r->right->key) {
    r = RotateLeft(r);
  }
  //case 4 ( right left)
  else if (bF < -1 && item < r->right->key) {
    r->right = RotateRight(r->right);
    r = RotateLeft(r);
  }
}


NodePtr AVLtree::RotateLeft(NodePtr x) {
  NodePtr y = x->right;
  x->right = y->left;
  y->left = x;

  //위치가 바뀌었으므로 높이 재조정
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

  return y;
}
    /*y를 중심으로 오른쪽으로 회전*/
NodePtr AVLtree::RotateRight(NodePtr y) {
  NodePtr x = y->left;
  y->left = x->right;
  x->right = y;

  //위치가 바뀌었으므로 높이 재조정
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

  return x;
}

int AVLtree::getBalanceFactor(NodePtr r){
  return getHeight(r->left) - getHeight(r->right);
}
int AVLtree::getHeight(NodePtr r){
  if(r == nullptr){
    return 0;
  }
  return r->height;
}