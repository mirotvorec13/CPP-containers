#include "../s21_pair.h"
#include "s21_containers_tests.h"

using namespace s21;

TEST(s21_pair, s21_pair_all) {
  Pair<int, int> test(1, 2);
  Pair<int, int> test2(1, 2);

  Pair<double, double> test3(1.1, 2.2);
  size_t size = 5;
  double val = 5.5;
  Pifpaf<double> obj(size, val);

  std::string s_back = "back";
  std::string s_front = "front";

  Pair<Pifpaf<double>, Pifpaf<double> > test_obj(obj, obj);

  std::tuple<int, int, int, double, double, double> t(1, 2, 3, 4.4, 5.5, 6.6);
  Pair<std::tuple<int, int, int, double, double, double>, double> test6(t, 1.1);

  Pair<int, int> test4(test);

  Pair<int, int> test5(*&test);

  Pifpaf<double> test_obj2(size, val);
  Pair<Pifpaf<double>, Pifpaf<double> > test7(test_obj2, test_obj2);
  Pair<Pifpaf<double>, Pifpaf<double> > test8 =
      std::move(test7);  // test8 = test7;
}
