#include "../header/bst_tree.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

// Fixture Class
template <typename T>
class BinarySearchTreeTest : public ::testing::Test {
 public:
  BinarySearchTreeTest() { cout << "Constructor called\n"; }
  virtual ~BinarySearchTreeTest() { cout << "Destructor called\n"; }

 protected:
  void SetUp() override {
    cout << "SetUp called\n";
    tree_.insert(4);
    tree_.insert(2);
    tree_.insert(6);
  }
  void TearDown() override { cout << "TearDown called\n"; }

  // BinarySearchTree<T> bst_;  // BST obj member
 protected:
  BinarySearchTree<int> tree_;
};

TEST_F(BinarySearchTree, test_bst_size) {
  EXPECT_EQ(3, tree_.getSize());
}

// int getSize();
// void addSize();
// bool isEmpty();
// NodePtr<T> IsKey(int item);
// int findDepthByValue(int item);