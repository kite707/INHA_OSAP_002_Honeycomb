#include "../header/bstTree.h"
#include <iostream>
using namespace std;

void bstTreetest() {
  cout << "hihihihihi" << endl;
}
/* constructor */
// template <typename T>
// BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {
//   cout << "bst 생성자 실행\n";
// };
template <>
void BinarySearchTree<int>::inheritTest() {
  cout << "inherit\n";
};