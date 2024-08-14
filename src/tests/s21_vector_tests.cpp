#include <vector>
#include <list>
#include "s21_containers_tests.h"
// #include "../s21_vector.h"

using namespace s21;

TEST(VectorTest, TestInitializerList) {
  Vector<int> v = {1, 2, 3, 4, 5};
  v.push_back(6);
  // auto it = v.begin();
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v.at(i);
  }
  std::cout << std::endl;
}

TEST(VectorTest, TestInitializerListTest) {
  Vector<int> v = {3, 4};
  Vector<int> v2(5, 6);
  std::vector<int> v3(5, 6);
  std::vector<std::vector<int>> v1 = {{std::vector<int>{1, 2}}, {std::vector<int>(v[0], v[1])}, {std::vector<int>(3, 4)}};
  std::vector<std::vector<int>*> v4 = {&v1[0], &v1[1], &v1[2]};
  Vector<Vector<int>> v_v = {{Vector<int>{1, 2}}, {Vector<int>(v[0], v[1])}, {Vector<int>{5, 6}}};
  Vector<Vector<int>*> v_v_p = {&v_v[0], &v_v[1], &v_v[2]};

  for (size_t i = 0; i < v4.size(); i++) {
    for (size_t j = 0; j < v4[i]->size(); j++) {
      std::cout << v4[i]->at(j);
    }
    std::cout << std::endl;
  }

  for (size_t i = 0; i < v_v_p.size(); i++) {
    for (size_t j = 0; j < v_v_p[i]->size(); j++) {
      std::cout << v_v_p[i]->at(j);
    }
    std::cout << std::endl;
  }

  for (size_t i = 0; i < v_v.size(); i++) {
    for (size_t j = 0; j < v_v[i].size(); j++) {
      std::cout << v_v[i].at(j);
    }
    std::cout << std::endl;
  }

  for (size_t i = 0; i < v_v_p.size(); i++) {
    delete v_v_p[i];
  }


}

TEST(VectorTest, TestInitialization) {
  std::list<int> l = {1, 2, 3, 4, 5};
  std::vector<int> v(*l.begin());
  // Vector<int> v(*l.begin());
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v.at(i);
  }
  std::cout << std::endl;
}