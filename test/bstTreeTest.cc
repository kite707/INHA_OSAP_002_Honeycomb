#include <gtest/gtest.h>
#include <iostream>
#include "../header/bstTree.h"
#include "../source/bstTree.cc"
using namespace testing;
using namespace std;

// Fixture Class
template <typename T>
class BinarySearchTreeTest : public Test {
 protected:
  void SetUp() override {
    // Init for testing
  }

  void TearDown() override {
    // Clean up
  }

  BinarySearchTree<T> bst;  // BST object
};

/*
TEST(BST, bstTree_Test) {
  EXPECT_EQ(8, test(4, 2));
*/