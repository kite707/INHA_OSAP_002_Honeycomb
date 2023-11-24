#include "../header/avl_tree.h"
#include <gtest/gtest.h>
#include "../header/bst_tree.h"
#include "../source/avl_tree.cc"
#include "../source/bst_tree.cc"
  // SetUp함수 실행 후 테스트 초기 상태
  //   2
  //  / \
  // 1   4
  //    / \
  //   3   5
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
  AVLTree<int> avl_;
};
AvlTreeTestFixture::AvlTreeTestFixture() {
  // std::cout << "Constructor called\n";
}

AvlTreeTestFixture::~AvlTreeTestFixture() {
  // std::cout << "Destructor called\n";
}

void AvlTreeTestFixture::SetUp() {
  std::cout << "[SetUp] 1~5삽입\n";
  avl_.insert(avl_.getRoot(), 1);
  avl_.insert(avl_.getRoot(), 2);
  avl_.insert(avl_.getRoot(), 3);
  avl_.insert(avl_.getRoot(), 4);
  avl_.insert(avl_.getRoot(), 5);
}
void AvlTreeTestFixture::TearDown() {
  // std::cout << "TearDown called\n";
}

