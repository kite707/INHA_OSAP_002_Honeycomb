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
  int getSize();
  void addSize();
  bool isEmpty();
  bool IsKey(int item);
  int findDepthByValue(int item);
  void minimum(int item);
  void maximum(int item);
  // + Implementation required...

 private:
  // data member of node pointer
  typedef Node<T>* NodePtr;
  // pointer of root node
  NodePtr root_;
  // total size of BST
  int size_;
};

#endif  // BSTTREE_H_
