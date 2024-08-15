#ifndef S21_PAIR_H
#define S21_PAIR_H

#include "initializer_list"
// #include <tuple>

namespace s21 {
template <class T1, class T2>
class Pair {
 public:
  using value_type1 = T1;
  using reference1 = T1&;
  using iterator1 = T1*;
  using value_type2 = T2;
  using reference2 = T2&;
  using iterator2 = T2*;

  T1 first;
  T2 second;

  // construct with two parameters
  Pair(value_type1 f, value_type2 s) : first(f), second(s){};
  // конструктор копирования
  Pair(const Pair& p) = default;
  // конструктор перемещения
  Pair(Pair&& p) = default;
  // деструктор
  ~Pair(){};

  // конструктор с параметром инициализации
  template <class Args1, class Args2>
  constexpr Pair(const Pair<Args1, Args2>& p)
      : first(p.first), second(p.second){};

  // конструктор перемещения с параметром инициализации
  template <class Args1, class Args2>
  constexpr Pair(Pair<Args1, Args2>&& p) noexcept {
    if (this != &p) {
      first = T1();
      second = T2();

      *this = p;
    }
  };

  // template <class... Args1, class... Args2>
  // Pair(std::piecewise_construct_t(), std::tuple<Args1...> first_args,
  //      std::tuple<Args2...> second_args) {
  //   first(std::make_from_tuple<T1>(first_args));
  //   second(std::make_from_tuple<T2>(second_args));
  // };

  constexpr bool operator==(const Pair& p) {
    return (this->first == p.first) && (this->second == p.second);
  }

  constexpr bool operator!=(const Pair& p) {
    return (this->first != p.first) || (this->second != p.second);
  }

  Pair& operator=(const Pair& p) {
    if (this != &p) {
      this->first = T1();
      this->second = T2();

      this->first = p.first;
      this->second = p.second;
    }
    return *this;
  }

  Pair& operator=(Pair&& p) noexcept {
    if (this != &p) {
      this->first = T1();
      this->second = T2();

      this->first = p.first;
      this->second = p.second;

      p.first = T1();
      p.second = T2();
      return *this;
    }
  }
};
}  // namespace s21

#endif  // S21_PAIR_H
