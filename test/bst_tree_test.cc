#include "../header/bst_tree.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

// Fixture Class
template <typename T>
class BST {
 public:
  BST() { cout << "Constructor called\n"; }
  virtual ~BST() { cout << "Destructor called\n"; }

 protected:
  void SetUp() override { cout << "SetUp called\n"; }
  void TearDown() override { cout << "TearDown called\n"; }

  TEST(SizeTest, bst_test) {
    tree_.insert(tree_.getRoot(), 4);
    tree_.insert(tree_.getRoot(), 2);
    tree_.insert(tree_.getRoot(), 6);

    EXPECT_EQ(3, tree_.getSize());
  }

  // BinarySearchTree<T> bst_;  // BST obj member
 protected:
  BinarySearchTree<int> tree_;
};
// int getSize();
// void addSize();
// bool isEmpty();
// NodePtr<T> IsKey(int item);
// int findDepthByValue(int item);