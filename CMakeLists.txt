cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS_PROFILE --coverage)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  tree_test
  test/avl_tree_test.cc
  test/bst_tree_test.cc
  test/set_test.cc
  source/avl_tree.cc
  source/bst_tree.cc
  source/set.cc
)
target_link_libraries(
  tree_test
  GTest::gtest_main
)
option(ENABLE_COVERAGE "Enable coverage" OFF)


include(GoogleTest)
gtest_discover_tests(tree_test)
