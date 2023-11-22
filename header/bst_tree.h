#ifndef BSTTREE_H_
#define BSTTREE_H_

/* Node struct */
template <typename T>
struct Node {
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
  void Insert_helper(int item);
  NodePtr<T> insert(NodePtr<T> node, int item);
  // + Implementation required...

 private:
  // pointer of root node
  NodePtr<T> root_;
  // total size of BST
  int size_;
};

#endif  // BSTTREE_H_
