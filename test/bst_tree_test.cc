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

/* 테스트: maximum */
TEST_F(BinaryTreeTestFixture, TestMaximum) {
  int items[] = {1, 6, 5, 10, 17, 14, 21};
  for (const int item : items) {
    this->bst_.Insert(item);
  }

  int max = this->bst_.maximum(17);
  cout << "17이 루트인 부분트리의 최댓값: " << max << "\n";
  EXPECT_EQ(21, max);

  // 더 테스트 필요함.
}

/* 테스트: insert */
TEST_F(BinaryTreeTestFixture, TestInsert) {
  int items[] = {1, 6, 5, 10, 7, 14, 21};
  for (const int item : items) {
    this->bst_.Insert(item);
  }

  NodePtr<int> node1 = this->bst_.IsKey(1);
  EXPECT_EQ(node1->key, 1) << "테스트 실패";
  NodePtr<int> node6 = this->bst_.IsKey(6);
  EXPECT_EQ(node6->key, 6) << "테스트 실패";
  NodePtr<int> node7 = this->bst_.IsKey(7);
  EXPECT_EQ(node7->key, 7) << "테스트 실패";

  /*
  NodePtr<int> node10 = this->bst_.IsKey(10);
  EXPECT_EQ(node10->key, 11) << "테스트 실패";  // 일부러 실패하는 케이스 생성
  */
}

// 테스트: recursiveInsert
TEST_F(BinaryTreeTestFixture, TestRecursiveInsert) {
  int items[] = {1, 6, 5, 10, 7, 14, 21};
  NodePtr<int> root = nullptr;
  for (const int item : items) {
    bst_.Insert(item);
  }

  root = this->bst_.getRoot();
  EXPECT_EQ(root, this->bst_.getRoot());

  EXPECT_TRUE(this->bst_.IsKey(1) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(6) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(5) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(10) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(7) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(14) != nullptr);
  EXPECT_TRUE(this->bst_.IsKey(21) != nullptr);

  /*
  EXPECT_TRUE(this->bst_.IsKey(22) != nullptr);  // 일부러 실패하는 케이스 생성
  */
}
// -----abyss-s-----

/* 테스트 실행 */
int main(int argc, char** argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}