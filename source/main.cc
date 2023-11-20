#include <iostream>
#include "../header/avlTree.h"
#include "../header/bstTree.h"
#include "../source/avlTree.cc"
using namespace std;

int main() {
  bstTreetest();
  BinarySearchTree<int> bst;
  bst.inheritTest();

  AVLTree<int> avl;
  cout << avl.avlMemberGetter() << endl;

  //  bst.inheritTest();
  // cout << tttt() << endl;
}