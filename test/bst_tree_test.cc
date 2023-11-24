#include "../header/bst_tree.h"
#include "../source/bst_tree.cc"
#include "gtest/gtest.h"

#include <iostream>
using namespace std;

// Fixture Class

class BinaryTreeTestFixture : public testing::Test {
 public:
  BinaryTreeTestFixture();
  virtual ~BinaryTreeTestFixture();

 protected:
  void SetUp() override;
  void TearDown() override;

  // BinarySearchTree<T> bst_;  // BST obj member
 protected:
  BinarySearchTree<int> bst_;
};

BinaryTreeTestFixture::BinaryTreeTestFixture() {
  cout << "Constructor called\n";
}
BinaryTreeTestFixture::~BinaryTreeTestFixture() {
  cout << "Destructor called\n";
}

void BinaryTreeTestFixture::SetUp() {
  cout << "SetUp called\n";

  bst_.insert(bst_.getRoot(), 4);
  bst_.insert(bst_.getRoot(), 2);
  bst_.insert(bst_.getRoot(), 6);
}

void BinaryTreeTestFixture::TearDown() {
  cout << "TearDown called\n";
}

TEST_F(BinaryTreeTestFixture, test_bst_isEmpty) {
  EXPECT_EQ(false, bst_.isEmpty());
}

TEST_F(BinaryTreeTestFixture, test_bst_size) {
  EXPECT_EQ(3, bst_.getSize());
}

TEST_F(BinaryTreeTestFixture, test_bst_isKey) {
  NodePtr<int> test_node = bst_.getRoot();
  EXPECT_EQ(test_node, bst_.IsKey(4));
}

TEST_F(BinaryTreeTestFixture, test_bst_findDepthByValue) {
  EXPECT_EQ(1, bst_.findDepthByValue(2));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// int getSize();
// void addSize();
// bool isEmpty();
// NodePtr<T> IsKey(int item);
// int findDepthByValue(int item);