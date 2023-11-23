#include "../header/bst_tree.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

// Fixture Class
template <typename T>
class BST : public ::testing::Test {
 public:
  BST() { cout << "Constructor called\n"; }
  virtual ~BST() { cout << "Destructor called\n"; }

 protected:
  void SetUp() override {
    cout << "SetUp called\n";
    tree_.insert(tree_.getRoot(), 4);
    tree_.insert(tree_.getRoot(), 2);
    tree_.insert(tree_.getRoot(), 6);
  }
  void TearDown() override { cout << "TearDown called\n"; }

  // BinarySearchTree<T> bst_;  // BST obj member
 protected:
  BinarySearchTree<int> tree_;
};

TEST(BST, test_bst_size) {
  BinarySearchTree<int> t;
  t.insert(t.getRoot(), 4);
  t.insert(t.getRoot(), 2);
  t.insert(t.getRoot(), 6);

  EXPECT_EQ(3, t.getSize());
}

// int getSize();
// void addSize();
// bool isEmpty();
// NodePtr<T> IsKey(int item);
// int findDepthByValue(int item);