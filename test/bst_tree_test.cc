#include "../header/bst_tree.h"
#include <gtest/gtest.h>
#include <iostream>
#include "../source/bst_tree.cc"
using namespace testing;
using namespace std;

// Fixture Class
class BinaryTreeTestFixture : public Test {
 public:
  BinaryTreeTestFixture();
  virtual ~BinaryTreeTestFixture();
  void SetUp() override;
  void TearDown() override;

 protected:
  BinarySearchTree<int> bst_;
};

/* Constructor */
BinaryTreeTestFixture::BinaryTreeTestFixture() {
  cout << "Constructor called\n";
}

/* Destructor */
BinaryTreeTestFixture::~BinaryTreeTestFixture() {
  cout << "Destructor called\n";
}

/* SetUp */
void BinaryTreeTestFixture::SetUp() {
  // 초기화
  cout << "SetUp called\n";
}

/* TearDown */
void BinaryTreeTestFixture::TearDown() {
  // 종료
  cout << "TearDown called\n";
}

// -----wuzoo-----
/*
* TEST_F(BinaryTreeTestFixture, test_bst_isEmpty) {
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
*/
// -----wuzoo-----

// -----abyss-s-----
/* 테스트: getRoot */
TEST_F(BinaryTreeTestFixture, TestGetRoot) {
  NodePtr<int> root = this->bst_.getRoot();
  EXPECT_EQ(root, this->bst_.getRoot());
}
/* 테스트: minimum */
TEST_F(BinaryTreeTestFixture, TestMinimum) {
  int items[] = {1, 6, 5, 10, 7, 14, 21};
  for (const int item : items) {
    this->bst_.Insert(item);
  }

  int min = this->bst_.minimum(10);  // 채점서버용 테스트: 최솟값 및 depth 출력
  cout << "10보다 작은 최솟값: " << min << "\n";
  EXPECT_EQ(7, min);

  min = this->bst_.minimum(6);
  cout << "6보다 작은 최솟값: " << min << "\n";
  EXPECT_EQ(5, min);
}
// -----abyss-s-----

/* 테스트 실행 */
int main(int argc, char** argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}