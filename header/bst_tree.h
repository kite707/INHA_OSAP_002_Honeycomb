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

/* BST Class */
template <typename T>
class BinarySearchTree {
  // data member of node pointer

 private:
  typedef Node<T>* NodePtr;
  // pointer of root node
  NodePtr root_;
  // total size of BST
  int size_;

 public:
  BinarySearchTree();
  NodePtr IsKey(int item);
  NodePtr insert(NodePtr node, int item);
  void Insert_helper(int item);
  int findDepthByValue(int item);
  bool isEmpty();
  int getSize();
  NodePtr getRoot();

  void addSize();
  /*NodePtr erase(NodePtr node, int item);*/
};

#endif  // BSTTREE_H_
