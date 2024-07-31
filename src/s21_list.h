#ifndef S21_LIST_H
#define S21_LIST_H

#include <iostream>

namespace s21 {
template <typename T>
class SequenceContainer {
 public:
};
template <typename T>
class List {
 private:
  T data;
  List *next;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  // конструктор по умолчанию
  List() : data(), next(nullptr){};
  // конструктор с данными
  List(value_type value) : data(value), next(nullptr){};
  explicit List(size_type n) : m_size(n), m_capacity(n), arr(n ? new T[n] : nullptr) {}
        // initializer list constructor (allows creating lists with initializer lists, see main.cpp)
        Vector(std::initializer_list<value_type> const &items);
  // конструктор копирования
  List(const List &v) : data(v.data), next(v.next){};
  // конструктор переноса
  List(List &&v) : data(v.data), next(v.next) { v.~List(); };
  // деструктор
  ~List();
  List operator=(const List &other);
  List operator==(const List &other);
  List operator()(const List &other);

};
}  // namespace s21

#endif