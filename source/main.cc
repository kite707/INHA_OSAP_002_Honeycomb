#include <iostream>
#include "../header/adaptor.h"
#include "../header/avl_tree.h"
#include "../header/bst_tree.h"
#include "../header/set.h"
#include "../source/avl_tree.cc"
#include "../source/bst_tree.cc"
using namespace std;

int main() {
  Set tmp;
  cout << tmp.sub(3, 1) << endl;
  // Adaptor<int>* ad = new AVLTree<int>;
  // ad->insert(1);
  // ad->insert(2);
  // ad->insert(3);
  // ad->insert(4);
  // cout << ad->find(1) << endl;
  // cout << ad->find(4) << endl;
  // cout << ad->empty() << endl;
  // cout << ad->size() << endl;
  /*AVLTree<int> avl;
  Node<int>* root = nullptr;
  root = avl.Insert(root, 42);
  cout << root->key << endl;*/
}