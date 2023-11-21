#include "../header/bst_tree.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace testing;
using namespace std;

// Fixture Class
template <typename T>
class BinarySearchTreeTest : public Test {
 public:
  BinarySearchTreeTest();
  virtual ~BinarySearchTreeTest();
  void SetUp() override;
  void TearDown() override;

 protected:
  BinarySearchTree<T> bst_;  // BST obj member
};

/* Constructor */
template <typename T>
BinarySearchTreeTest<T>::BinarySearchTreeTest() {
  cout << "Constructor called\n";
}

/* Destructor */
template <typename T>
BinarySearchTreeTest<T>::~BinarySearchTreeTest() {
  cout << "Destructor called\n";
}

/* SetUp */
template <typename T>
void BinarySearchTreeTest<T>::SetUp() {
  cout << "SetUp called\n";
}

/* TearDown */
template <typename T>
void BinarySearchTreeTest<T>::TearDown() {
  cout << "TearDown called\n";
}