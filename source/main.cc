#include <iostream>
#include "../header/avl_tree.h"
#include "../header/bst_tree.h"
#include "../source/avl_tree.cc"
#include "../source/bst_tree.cc"
using namespace std;

int main() {
  AVLTree<int> avl;
  Node<int>* root = nullptr;
  root = avl.Insert(root, 42);
  cout << root->key << endl;
}