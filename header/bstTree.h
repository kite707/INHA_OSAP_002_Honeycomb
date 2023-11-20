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
  int getSize();
  void addSize();
  bool isEmpty();

 private:
  typedef Node<T>* NodePtr;
  NodePtr root;
  int size;
};

#endif  // BSTTREE_H_