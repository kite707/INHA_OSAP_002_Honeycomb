#include "../header/set.h"
#include <gtest/gtest.h>
#include <iostream>
#include "../header/adaptor.h"
#include "../header/avl_tree.h"
#include "../source/avl_tree.cc"
#include "../source/set.cc"

// Set constructor test
TEST(SetTest, ConstructorTest) {
  Adaptor<int>* adaptor = new AVLTree<int>;
  Set<int> set(adaptor);
  int size = set.size();

  ASSERT_EQ(0, size);
}

class SetParametrizedTestFixture
    : public ::testing::TestWithParam<std::tuple<int, int>> {
 public:
  void SetUp() override;
  void TearDown() override{};

 protected:
  Set<int>* set;
};


class SetFixture : public testing::Test {
 public:
  void SetUp() override;
  void TearDown() override{};

 protected:
  Set<int>* set;
};

// setUp main에서와 같이 adaptor를 이용해서 new AVLTree 생성
void SetFixture::SetUp() {
  Adaptor<int>* adaptor = new AVLTree<int>;
  set = new Set<int>(adaptor);
  cout << "SetUp" << '\n';
  set->insert(1);
  set->insert(5);

  // 초기 상태
  //     1
  //      \
  //       5
}

TEST_F(SetFixture, SetFind) {
// 초기 상태
  //     1
  //      \
  //       5
 ASSERT_EQ(0, set->find(1));
 ASSERT_EQ(1, set->find(5));
}

TEST_F(SetFixture, SetSize) {
// 초기 상태
  //     1
  //      \
  //       5
 ASSERT_EQ(2, set->size());
 set->insert(3);
 ASSERT_EQ(3, set->size());
}

// setUp main에서와 같이 adaptor를 이용해서 new AVLTree 생성
void SetParametrizedTestFixture::SetUp() {
  Adaptor<int>* adaptor = new AVLTree<int>;
  set = new Set<int>(adaptor);
  cout << "SetUp" << '\n';
  set->insert(1);
  set->insert(5);

  // 초기 상태
  //     1
  //      \
  //       5
}

TEST_P(SetParametrizedTestFixture, InsertTest) {
  std::tuple<int, int> tuple = GetParam();

  // tuple에서 첫번째 값은 insert에 들어갈 변수 값,
  // 두 번째 값은 예상되는 depth값
  int param = std::get<0>(tuple);
  int expected_value = std::get<1>(tuple);

  std::cout << "insert 값 : " << param
            << " 예상되는 depth 값 = " << expected_value << '\n';

  set->insert(param);
  // 실제 depth값
  int actual_value = set->find(param);
  std::cout << "실제 depth 값 : " << actual_value << '\n';

  ASSERT_EQ(expected_value, actual_value);
}

INSTANTIATE_TEST_CASE_P(InsertTest,
                        SetParametrizedTestFixture,
                        ::testing::Values(std::make_tuple(2, 0),
                                          std::make_tuple(3, 0),
                                          std::make_tuple(4, 0),
                                          std::make_tuple(6, 1)));
