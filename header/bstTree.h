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
  int get_size();
  void set_size_plus();
  bool isEmpty();
  bool IsKey(int item);
  int findDepthByValue(int item);

 private:
  typedef Node<T>* NodePtr;
  NodePtr root_;
  int size_;
};

#endif  // BSTTREE_H_