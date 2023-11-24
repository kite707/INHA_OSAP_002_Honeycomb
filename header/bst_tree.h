#ifndef BSTTREE_H_
#define BSTTREE_H_

/* Node struct */
template <typename T>
struct Node {  // clang format apply
  T key;
  Node* left = nullptr;
  Node* right = nullptr;
  int height = 1;
};

template <typename T>
using NodePtr = Node<T>*;

/* BST Class */
template <typename T>
class BinarySearchTree {
 public:
  BinarySearchTree();
  int getSize();
  void addSize();
  bool isEmpty();
  NodePtr<T> IsKey(int item);
  int findDepthByValue(int item);
  void minimum(int item);
  void maximum(int item);
  NodePtr<T> getRoot();
  virtual NodePtr<T> recursiveInsert(NodePtr<T> node, int item);
  void Insert(int item);
  int getHeight(NodePtr<T> current_node);
  // + Implementation required...

 protected:
  // pointer of root node
  NodePtr<T> root_;
  // total size of BST
  int size_;
};

#endif  // BSTTREE_H_