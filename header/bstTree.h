#ifndef BSTTREE_H_
#define BSTTREE_H_

int multiple(int a, int b); // 스켈레톤 코드

/* Node 구조체 */
template <typename T>
struct Node {
  T key;
  Node* left;
  Node* right;
  int height;
};

/* BST 클래스 */
template <typename T>
class BinarySearchTree {
 public:
  BinarySearchTree();
  // 멤버 함수 구현 필요
 private:
  typedef Node<T>* NodePtr;
  NodePtr root;
};
#endif  // BSTTREE_H_




