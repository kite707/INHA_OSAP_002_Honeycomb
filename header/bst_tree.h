#ifndef BSTTREE_H_
#define BSTTREE_H_

/* Node struct */
template <typename T>
using NodePtr = Node<T>*;

template <typename T>
struct Node {
  T key;
  Node* left = nullptr;
  Node* right = nullptr;
  int height = 1;
};

/* BST Class */
template <typename T>
class BinarySearchTree {
 public:
  BinarySearchTree();
  int getSize();
  void addSize();
  bool isEmpty();
  bool IsKey(int item);
  int findDepthByValue(int item);
  void minimum(int item);
  void maximum(int item);
  NodePtr<T> getRoot();
  void Insert_helper(int item);
  NodePtr<T> insert(NodePtr node, int item);
  // + Implementation required...

 private:
  // data member of node pointer

  // pointer of root node
  NodePtr<T> root_;
  // total size of BST
  int size_;
};

#endif  // BSTTREE_H_
