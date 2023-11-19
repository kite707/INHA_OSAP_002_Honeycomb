#ifndef BSTTREE_H_
#define BSTTREE_H_

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
  BinarySearchTree();
  // member func...
 private:
  typedef Node<T>* NodePtr;
  NodePtr root;
};

#endif  // BSTTREE_H_