#include "s21_containers_tests.h"

TEST(VectorTest, TestInitializerList) {
  Vector<int> v = {1, 2, 3, 4, 5};
  v.push_back(6);
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v.at(i);
  }
  cout << endl;
}