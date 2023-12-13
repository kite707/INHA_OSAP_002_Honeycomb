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

// 매개변수화 테스트 클래스
class SetParametrizedTestFixture
    : public ::testing::TestWithParam<std::tuple<int, int>> {
 public:
  void SetUp() override;
  void TearDown() override{};

 protected:
  Set<int>* set;
};

// Fixture 테스트 클래스
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

// find test
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

// empty test
TEST_F(SetFixture, SetEmpty) {
  // 초기 상태
  //     1
  //      \
  //       5
  ASSERT_EQ(0, set->empty());
}

// maximum test
TEST_F(SetFixture, SetMaximum) {
  // 초기 상태
  //     1
  //      \
  //       5
  ASSERT_EQ(5, set->maximum(1));
  set->insert(6);
  //     5
  //    / \
  //   1   6
  ASSERT_EQ(6, set->maximum(5));
}

// minimum test
TEST_F(SetFixture, SetMinimum) {
  // 초기 상태
  //     1
  //      \
  //       5
  ASSERT_EQ(1, set->minimum(1));
  //     5
  //    / \
  //   1   6
  set->insert(6);
  ASSERT_EQ(1, set->minimum(5));
  //     5
  //    / \
  //   1   7
  //      / \
  //     6   8
  set->insert(8);
  set->insert(7);
  ASSERT_EQ(1, set->minimum(5));
  ASSERT_EQ(6, set->minimum(7));
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
