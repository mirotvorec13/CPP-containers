#include <list>
#include <vector>

#include "s21_containers_tests.h"
#include "../s21_vector.h"


using namespace s21;
using namespace std;

TEST(VectorTest, TestInitialization) {
  Vector<int> v(5, 3);
  for (auto it = v.begin(); it < v.end(); ++it) {
    ASSERT_EQ(*it, 3);
  }

  for (size_t it = 0; it < v.size(); ++it) {
    ASSERT_EQ(v.at(it), 3);
  }

  v.resize(8);
  ASSERT_EQ(v.size(), 5);
  ASSERT_EQ(v.capacity(), 8);

  v.push_back(8);
  ASSERT_EQ(v.back(), 8);
  v[3] = 8888;
  ASSERT_EQ(v[3], 8888);
}


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

  ASSERT_EQ(v.capacity(), 7);
  v.pop_back();
  v.pop_back();
  v.pop_back();
  ASSERT_EQ(v.capacity(), 7);
  ASSERT_EQ(v.size(), 4);
}

TEST(VectorTest, TestReserveResize) {
  Vector<int> v = {1, 2, 3, 4, 5};
  v.reserve(10);
  ASSERT_EQ(v.capacity(), 10);
  ASSERT_EQ(v.size(), 5);
  v.reserve(5);
  ASSERT_EQ(v.capacity(), 5);
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

TEST(VectorTest, TestVectorInt) {
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
  ASSERT_EQ(v_v[1][3], 4);
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
  ASSERT_EQ(v.capacity(), 6);
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

TEST(VectorTest, TestInsertIterator) {
  // сравниваем со стандартным вектором
  Vector<int> v = {1, 2, 3, 4, 5};
  std::vector<int> st_v = {1, 2, 3, 4, 5};
  Vector<int>::iterator it = v.insert(v.cbegin(), 0);
  std::vector<int>::iterator st_it = st_v.insert(st_v.cbegin(), 0);

  ASSERT_EQ(v.size(), 6);
  ASSERT_EQ(*it, 0);
  ASSERT_EQ(st_v.size(), 6);
  ASSERT_EQ(*st_it, 0);
  Vector<int>::iterator itz = it + 5;
  ASSERT_EQ(*itz, 5);
  std::vector<int>::iterator st_itz = st_it + 5;
  ASSERT_EQ(*st_itz, 5);
  auto at = v.insert(v.cbegin(), 5, 88);
  auto st_at = st_v.insert(st_v.cbegin(), 5, 88);

  ASSERT_EQ(v.size(), 11);
  ASSERT_EQ(*at, 88);
  (at = at + 1);
  ASSERT_EQ(*at, 88);

  ASSERT_EQ(st_v.size(), 11);
  ASSERT_EQ(*st_at, 88);
  (st_at = st_at + 1);
  ASSERT_EQ(*st_at, 88);
  
  auto new_at_it = v.insert(at, 77);
  ASSERT_EQ(v.capacity(), 12); // мое выделение памяти
  st_v.insert(st_at, 77);
  ASSERT_EQ(st_v.capacity(), 12); // увеличение памяти разниться

  Vector<int>::iterator iter = v.insert(new_at_it, 98798);
  Vector<int> res = {88, 98798, 77, 88, 88, 88, 88, 0, 1, 2, 3, 4, 5};
  for (; iter < v.end(); ++iter) { }
  iter--;
  Vector<int>::iterator iter_res = res.rbegin();
  for (; iter > v.begin();) {
    ASSERT_EQ(*iter--, *iter_res--);
  }

  std::vector<int>::iterator st_iter = st_v.insert(st_at, 98798);
  Vector<int> st_res = {88, 98798, 77, 88, 88, 88, 88, 0, 1, 2, 3, 4, 5};
  for (; st_iter < st_v.end(); ++st_iter) { }
  st_iter--;
  Vector<int>::iterator st_iter_res = st_res.rbegin();
  for (; st_iter > st_v.begin();) {
    ASSERT_EQ(*st_iter--, *st_iter_res--);
  }
  
  ASSERT_EQ(*iter, *iter_res);
  for (; iter < v.end();) {
    ASSERT_EQ(*iter++, *iter_res++);
  }
  iter = iter - 6;

  ASSERT_EQ(*st_iter, *st_iter_res);
  for (; st_iter < st_v.end();) {
  ASSERT_EQ(*st_iter++, *st_iter_res++);
  }
  st_iter = st_iter - 6;

  Vector<int> vec = {333, 999, 222, 111};
  Vector<int> new_res = {88, 98798, 77, 88, 88, 88, 88, 333, 999, 222, 111, 0, 1, 2, 3, 4, 5};
  Vector<int>::iterator new_iterator = v.insert(iter, vec.begin(), vec.end());
  Vector<int>::iterator new_iterator_res = new_res.begin();
  for (;new_iterator > v.begin(); --new_iterator) { }
  for (; new_iterator < v.end(); ++new_iterator) {
    ASSERT_EQ(*new_iterator_res++, *new_iterator);
  }

  std::vector<int> st_vec = {333, 999, 222, 111};
  std::vector<int> st_new_res = {88, 98798, 77, 88, 88, 88, 88, 333, 999, 222, 111, 0, 1, 2, 3, 4, 5};
  std::vector<int>::iterator st_new_iterator = st_v.insert(st_iter, st_vec.begin(), st_vec.end());
  std::vector<int>::iterator st_new_iterator_res = st_new_res.begin();
  for (;st_new_iterator > st_v.begin(); --st_new_iterator) { }
  for (; st_new_iterator < st_v.end(); ++st_new_iterator) {
    ASSERT_EQ(*st_new_iterator_res++, *st_new_iterator);
  }
}

TEST(VectorTest, TestEraseIterator) {
  Vector<int> new_vec = {88, 98798, 77, 88, 88, 88, 88, 333, 999, 222, 111, 0, 1, 2, 3, 4, 5};
  Vector<int>::iterator it = new_vec.begin();
  for (size_t i = 0; i < 7; ++it, ++i) { }
  
  auto it_res = new_vec.erase(it);

  for (size_t i = 0; i < 3; ++it_res, ++i) { }
  new_vec.erase(it, it_res);
  Vector<int> res = {88, 98798, 77, 88, 88, 88, 88, 0, 1, 2, 3, 4, 5};

  for (auto it = new_vec.begin(), res_it = res.begin(); it < new_vec.end();) {
    ASSERT_EQ(*res_it++, *it++);
  }

}