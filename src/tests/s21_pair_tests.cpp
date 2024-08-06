#include "s21_containers_tests.h"

TEST(s21_pair, s21_pair_all) {
    
  Pair<int, int> test(1, 2);
  Pair<int, int> test2(1, 2);
  
  Pair<double, double> test3(1.1, 2.2);
  size_t size = 5;
  double val = 5.5;
  Pifpaf<double> obj(size, val);
  
  std::string s_back = "back";
  std::string s_front = "front";
  
  std::cout << test.first << " " << test.second << std::endl;

  Pair<Pifpaf<double>, Pifpaf<double> > test_obj(obj, obj);

  std::cout << test_obj.first.arr[0] << "  " << test_obj.second.size_arr << std::endl;
//   test.push_back(s_back);
//   test.push_front(s_front);
//   test=test_obj;
  
  for (auto iter = test_obj.first.begin(); iter < test_obj.first.end();  ++iter) {
    std::cout << *iter << std::endl;
  }
  std::tuple <int, int, int, double, double, double> t(1, 2, 3, 4.4, 5.5, 6.6);
  Pair<std::tuple <int, int, int, double, double, double>, double> test6(t, 1.1);

  Pair<int, int> test4(test);
  std::cout << test4.first << " " << test4.second << std::endl;
  std::cout << test.first << " " << test.second << std::endl;
  Pair<int, int> test5(*&test);

  std::cout << test5.first << " " << test5.second << std::endl;

  std::cout << ((test == test5) ? "true" : "false"); std::cout << std::endl;

  std::cout << std::get<0>(test6.first) << " " << test6.second << std::endl;
  std::cout << std::get<1>(test6.first) << " " << test6.second << std::endl;
  std::cout << std::get<2>(test6.first) << " " << test6.second << std::endl;
  std::cout << std::get<3>(test6.first) << " " << test6.second << std::endl;
  std::cout << std::get<4>(test6.first) << " " << test6.second << std::endl;
  std::cout << std::get<5>(test6.first) << " " << test6.second << std::endl;
  Pifpaf<double> test_obj2(size, val);
  Pair<Pifpaf<double>, Pifpaf<double> > test7(test_obj2, test_obj2);
  Pair<Pifpaf<double>, Pifpaf<double> > test8 = std::move(test7); // test8 = test7;

  std::cout << test8.first.arr[0] << "  " << test8.second.size_arr << std::endl;
  std::cout << test7.first.arr[0] << "  " << test7.second.size_arr << std::endl;

}
