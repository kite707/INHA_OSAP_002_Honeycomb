#include "../header/avl_tree.h"
#include <gtest/gtest.h>
#include "../header/bst_tree.h"
#include "../source/avl_tree.cc"
#include "../source/bst_tree.cc"

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
