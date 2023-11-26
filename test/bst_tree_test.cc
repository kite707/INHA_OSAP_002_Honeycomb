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
BinaryTreeTestFixture::BinaryTreeTestFixture() {}

/* Destructor */
BinaryTreeTestFixture::~BinaryTreeTestFixture() {}

/* SetUp */
void BinaryTreeTestFixture::SetUp() {
  int items[] = {1, 6, 5, 10, 7, 14, 21};
  NodePtr<int> root = nullptr;
  for (const int item : items) {
    bst_.insert(item);
  }
}

/* TearDown */
void BinaryTreeTestFixture::TearDown() {}

TEST_F(BinaryTreeTestFixture, TestIsEmpty) {
  EXPECT_EQ(false, bst_.isEmpty());
}

TEST_F(BinaryTreeTestFixture, TestGetSize) {
  EXPECT_EQ(7, bst_.getSize());
}

TEST_F(BinaryTreeTestFixture, TestAddSize) {
  EXPECT_EQ(7, bst_.getSize());
  bst_.addSize();
  EXPECT_EQ(8, bst_.getSize());
}

TEST_F(BinaryTreeTestFixture, TestIsKey) {
  NodePtr<int> test_node = bst_.getRoot();
  EXPECT_EQ(test_node, bst_.IsKey(1));
}

TEST_F(BinaryTreeTestFixture, TestFindDepthByValue) {
  EXPECT_EQ(2, bst_.findDepthByValue(5));
}

/* 테스트: getRoot */
TEST_F(BinaryTreeTestFixture, TestGetRoot) {
  NodePtr<int> root = this->bst_.getRoot();
  EXPECT_EQ(root, this->bst_.getRoot());
}

/* 테스트: minimum */
TEST_F(BinaryTreeTestFixture, TestMinimum) {
  int min = this->bst_.minimum(10);  // 채점서버용 테스트: 최솟값 및 depth 출력
  cout << "10보다 작은 최솟값: " << min << "\n";
  EXPECT_EQ(7, min);

  min = this->bst_.minimum(6);
  cout << "6보다 작은 최솟값: " << min << "\n";
  EXPECT_EQ(5, min);
}

/* 테스트: maximum */
TEST_F(BinaryTreeTestFixture, TestMaximum) {
  int max = this->bst_.maximum(7);
  cout << "7이 루트인 부분트리의 최댓값: " << max << "\n";
  EXPECT_EQ(7, max);
}

/* 테스트: insert */
TEST_F(BinaryTreeTestFixture, TestInsert) {
  NodePtr<int> node1 = this->bst_.IsKey(1);
  EXPECT_EQ(node1->key, 1) << "테스트 실패";
  NodePtr<int> node6 = this->bst_.IsKey(6);
  EXPECT_EQ(node6->key, 6) << "테스트 실패";
  NodePtr<int> node7 = this->bst_.IsKey(7);
  EXPECT_EQ(node7->key, 7) << "테스트 실패";
}

// 테스트: recursiveInsert
TEST_F(BinaryTreeTestFixture, TestRecursiveInsert) {
  NodePtr<int> root = this->bst_.getRoot();
  EXPECT_EQ(root, this->bst_.getRoot());

  EXPECT_TRUE(this->bst_.IsKey(1) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(6) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(5) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(10) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(7) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(14) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(21) != nullptr);
}

TEST_F(BinaryTreeTestFixture, TestRank) {
  EXPECT_EQ(1, bst_.rank(bst_.getRoot(), 1));
  EXPECT_EQ(7, bst_.rank(bst_.getRoot(), 21));
  EXPECT_EQ(5, bst_.rank(bst_.getRoot(), 10));
  EXPECT_EQ(4, bst_.rank(bst_.getRoot(), 7));
}

/* 테스트 실행 */
int main(int argc, char** argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}