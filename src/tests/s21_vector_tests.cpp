#include <list>
#include <vector>

#include "s21_containers_tests.h"
// #include "../s21_vector.h"

using namespace s21;

TEST(VectorTest, TestIterators) {
  Vector<int> v = {1, 2, 3, 4, 5};
  for (auto it = v.begin(); it < v.end(); ++it) {
    ASSERT_EQ(*it, it - v.begin() + 1);
  }
  for (auto it = v.rbegin(); it < v.rend(); ++it) {
    ASSERT_EQ(*it, v.size() - (it - v.rbegin()) + 1);
  }
  for (auto it = v.cbegin(); it < v.cend(); ++it) {
    ASSERT_EQ(*it, it - v.cbegin() + 1);
  }
  for (auto it = v.crbegin(); it < v.crend(); ++it) {
    ASSERT_EQ(*it, v.size() - (it - v.crbegin()) + 1);
  }
}

TEST(VectorTest, TestSize) {
  Vector<int> v = {1, 2, 3, 4, 5};
  ASSERT_EQ(v.size(), 5);
  v.pop_back();
  ASSERT_EQ(v.size(), 4);
  v.push_back(6);
  ASSERT_EQ(v.size(), 5);
}

TEST(VectorTest, TestCapacity) {
  Vector<int> v = {1, 2, 3, 4, 5};
  ASSERT_EQ(v.capacity(), 5);
  v.push_back(6);
  v.push_back(7);
  v.push_back(8);
  v.push_back(9);
  v.push_back(10);
  ASSERT_EQ(v.capacity(), 10);
  v.pop_back();
  v.pop_back();
  v.pop_back();
  v.pop_back();
  v.pop_back();
  ASSERT_EQ(v.capacity(), 10);
  ASSERT_EQ(v.size(), 5);
}

TEST(VectorTest, TestReserveResize) {
  Vector<int> v = {1, 2, 3, 4, 5};
  v.reserve(10);
  ASSERT_EQ(v.capacity(), 10);
  ASSERT_EQ(v.size(), 5);
  v.resize(10, 6);
  ASSERT_EQ(v.size(), 10);
  ASSERT_EQ(v.capacity(), 10);
  v.resize(5, 7);
  ASSERT_EQ(v.size(), 5);
  ASSERT_EQ(v.capacity(), 10);
  v.resize(15);
  ASSERT_EQ(v.size(), 5);
  ASSERT_EQ(v.capacity(), 15);
}

TEST(VectorTest, TestAt) {
  Vector<int> v = {1, 2, 3, 4, 5};
  ASSERT_EQ(v.at(0), 1);
  ASSERT_EQ(v.at(4), 5);
  v.at(4) = 6;
  ASSERT_EQ(v.at(4), 6);
}

TEST(VectorTest, TestOperatorBrackets) {
  Vector<int> v = {1, 2, 3, 4, 5};
  ASSERT_EQ(v[0], 1);
  ASSERT_EQ(v[4], 5);
  v[4] = 6;
  ASSERT_EQ(v[4], 6);
}

TEST(VectorTest, TestEmpty) {
  Vector<int> v = {1, 2, 3, 4, 5};
  ASSERT_EQ(v.empty(), false);
  v.clear();
  ASSERT_EQ(v.empty(), true);
}

TEST(VectorTest, TestClear) {
  Vector<int> v = {1, 2, 3, 4, 5};
  v.clear();
  ASSERT_EQ(v.size(), 0);
  ASSERT_EQ(v.empty(), true);
}

TEST(VectorTest, TestInitializerListInt) {
  Vector<int> v = {1, 2, 3, 4, 5};
  ASSERT_EQ(v.size(), 5);
  v.push_back(6);
  for (size_t i = 0; i < v.size(); i++) {
    ASSERT_EQ(v[i], i + 1);
  }
}

TEST(VectorTest, TestInitializerListTestVectorInt) {
  Vector<int> v = {3, 4};
  Vector<int> v2(5, 6);
  for (size_t i = 0; i < v2.size(); i++) {
    ASSERT_EQ(v2[i], 6);
  }
  ASSERT_EQ(v2.size(), 5);
  ASSERT_EQ(v.size(), 2);
  for (size_t i = 0; i < v.size(); i++) {
    ASSERT_EQ(v[i], i + 3);
  }
  Vector<Vector<int>> v_v = {
      {Vector<int>{1, 2}}, {Vector<int>(v[1], v[1])}, {Vector<int>{5, 6}}};
  ASSERT_EQ(v_v[0][0], 1);
  ASSERT_EQ(v_v[0][1], 2);
  ASSERT_EQ(v_v[1][0], 4);
  ASSERT_EQ(v_v[1][1], 4);
  ASSERT_EQ(v_v[1][2], 4);
  ASSERT_EQ(v_v[2][0], 5);
  ASSERT_EQ(v_v[2][1], 6);
  Vector<Vector<int>*> v_v_p = {&v_v[0], &v_v[1], &v_v[2]};
  Vector<Vector<Vector<int>>> v_v_v = {
      {Vector<Vector<int>>{
          {Vector<int>{1, 2}}, {Vector<int>(v[0], v[1])}, {Vector<int>{5, 6}}}},
      {Vector<Vector<int>>{{Vector<int>{4, 8}},
                           {Vector<int>{v[0], v[1]}},
                           {Vector<int>{88, 6223}}}}};

  ASSERT_EQ(v_v.size(), 3);
  ASSERT_EQ(v_v_p.size(), 3);
  ASSERT_EQ(v_v_v.size(), 2);
  ASSERT_EQ(v_v_v[0][0][0], 1);
  ASSERT_EQ(v_v_v[0][0][1], 2);
  ASSERT_EQ(v_v_v[0][1][0], 4);
  ASSERT_EQ(v_v_v[0][1][1], 4);
  ASSERT_EQ(v_v_v[0][1][2], 4);
  ASSERT_EQ(v_v_v[0][2][0], 5);
  ASSERT_EQ(v_v_v[0][2][1], 6);
  ASSERT_EQ(v_v_v[1][0][0], 4);
  ASSERT_EQ(v_v_v[1][0][1], 8);
  ASSERT_EQ(v_v_v[1][1][0], 3);
  ASSERT_EQ(v_v_v[1][1][1], 4);
  ASSERT_EQ(v_v_v[1][2][0], 88);
  ASSERT_EQ(v_v_v[1][2][1], 6223);

  ASSERT_EQ(v_v_p[0]->at(0), 1);
  ASSERT_EQ(v_v_p[0]->at(1), 2);
  ASSERT_EQ(v_v_p[1]->at(0), 4);
  ASSERT_EQ(v_v_p[1]->at(1), 4);
  ASSERT_EQ(v_v_p[1]->at(2), 4);
  ASSERT_EQ(v_v_p[1]->at(3), 4);
  ASSERT_EQ(v_v_p[2]->at(0), 5);
  ASSERT_EQ(v_v_p[2]->at(1), 6);
}

TEST(VectorTest, TestInitializationInt) {
  Vector<int> v = {1, 2, 3, 4, 5};
  ASSERT_EQ(v.size(), 5);
  ASSERT_EQ(v.empty(), false);
  ASSERT_EQ(v[2], 3);
  ASSERT_EQ(v.capacity(), 5);

  Vector<int> v2(v);
  ASSERT_EQ(v2.size(), 5);
  ASSERT_EQ(v2.empty(), false);
  ASSERT_EQ(v2[2], 3);
  ASSERT_EQ(v2.capacity(), 5);

  Vector<int> v3(std::move(v2));
  ASSERT_EQ(v3.size(), 5);
  ASSERT_EQ(v3.empty(), false);
  ASSERT_EQ(v3[2], 3);
  ASSERT_EQ(v3.capacity(), 5);

  Vector<int> v6;
  v6 = std::move(v);
  ASSERT_EQ(v6.size(), 5);
  ASSERT_EQ(v6.empty(), false);
  ASSERT_EQ(v6[2], 3);
  ASSERT_EQ(v6.capacity(), 5);

  Vector<int> v4 = {1, 2, 88, 4, 5};
  Vector<int> v5 = v4;
  ASSERT_EQ(v5.size(), 5);
  ASSERT_EQ(v5.empty(), false);
  ASSERT_EQ(v5[2], 88);
  ASSERT_EQ(v5.capacity(), 5);
}

TEST(VectorTest, TestPushBackInt) {
  Vector<int> v = {1, 2, 3, 4, 5};
  v.push_back(6);
  ASSERT_EQ(v.size(), 6);
  ASSERT_EQ(v[5], 6);
  ASSERT_EQ(v.capacity(), 10);
}

TEST(VectorTest, TestPopBackInt) {
  Vector<int> v = {1, 2, 3, 4, 5};
  v.pop_back();
  ASSERT_EQ(v.size(), 4);
  ASSERT_EQ(v[3], 4);
  ASSERT_EQ(v.capacity(), 5);
}

TEST(VectorTest, TestInitializationDouble) {
  Vector<double> v = {1.1, 2.2, 3.3, 4.4, 5.5};
  ASSERT_EQ(v.size(), 5);
  ASSERT_EQ(v.empty(), false);
  ASSERT_EQ(v[2], 3.3);
  ASSERT_EQ(v.capacity(), 5);
}

TEST(VectorTest, TestInitializationString) {
  Vector<std::string> v = {"1wer", "2lkj", "3fd", "4xcv", "5.,m"};
  ASSERT_EQ(v.size(), 5);
  ASSERT_EQ(v.empty(), false);
  ASSERT_EQ(v[2], "3fd");
  ASSERT_EQ(v.capacity(), 5);
}