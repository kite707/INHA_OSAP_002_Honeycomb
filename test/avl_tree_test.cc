#include "../header/avl_tree.h"
#include <gtest/gtest.h>
#include "../header/bst_tree.h"
#include "../source/avl_tree.cc"
#include "../source/bst_tree.cc"
// SetUp함수 실행 후 테스트 초기 상태
//   1
//    \
//     2

TEST(AVLTreeTest, ConstructorTest) {
  AVLTree<int> avl;

  int size = avl.getSize();

  ASSERT_EQ(0, size);
  ASSERT_EQ(nullptr, avl.getRoot());
}
class AvlTreeTestFixture : public testing::Test {
 public:
  AvlTreeTestFixture();
  virtual ~AvlTreeTestFixture();
  void SetUp() override;
  void TearDown() override;

 protected:
  int getBalanceFactorWrapper(NodePtr<int> current_node) {
    return avl_.getBalanceFactor(current_node);
  }

 protected:
  AVLTree<int> avl_;
};
AvlTreeTestFixture::AvlTreeTestFixture() {
  // std::cout << "Constructor called\n";
}

AvlTreeTestFixture::~AvlTreeTestFixture() {
  // std::cout << "Destructor called\n";
}

void AvlTreeTestFixture::SetUp() {
  std::cout << "[SetUp] 1~2삽입\n";
  avl_.insert(1);
  avl_.insert(2);
}
void AvlTreeTestFixture::TearDown() {
  // std::cout << "TearDown called\n";
}

// 현재 상태(1~3 삽입)
//   2
//  / \
// 1   3
TEST_F(AvlTreeTestFixture, recursiveInsertTest) {
  this->avl_.recursiveInsert(avl_.getRoot(), 3);
  ASSERT_EQ(1, this->avl_.findDepthByValue(3));
}

// 현재 상태(1~3 삽입)
//   2
//  / \
// 1   3
TEST_F(AvlTreeTestFixture, insertTest_General) {
  this->avl_.insert(3);
  ASSERT_EQ(1, this->avl_.findDepthByValue(1));
  ASSERT_EQ(0, this->avl_.findDepthByValue(2));
  ASSERT_EQ(1, this->avl_.findDepthByValue(3));
}

// 현재 상태(1~4 삽입)
//   2
//  / \
// 1   3
//      \
//       4
TEST_F(AvlTreeTestFixture, getBalanceFactorTest) {
  this->avl_.insert(3);
  this->avl_.insert(4);
  ASSERT_EQ(-1, this->avl_.getBalanceFactor(this->avl_.getRoot()));
}