#ifndef BSTTREE_H_
#define BSTTREE_H_
#include <iostream>

void bstTreetest();

/* Node struct */
template <typename T>
struct Node {
  T key;
  Node* left;
  Node* right;
  int height;
};

/* BST Class */
template <typename T>
class BinarySearchTree {
 public:
  BinarySearchTree() : root(nullptr) { std::cout << "bst 생성자 실행\n"; };
  // member func...
  void inheritTest();

 private:
  typedef Node<T>* NodePtr;
  NodePtr root;
};
#endif  // BSTTREE_H_