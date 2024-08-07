#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <iostream>
#include <exception>
#include <initializer_list>

/*
HEADER FILE
*/

// Test vector class with some basic example operations and concepts
namespace s21 {
template <class T>
class Vector {
  // private attributes
 private:
  size_t m_size;
  size_t m_capacity;
  T *arr;
  // public attribures
 public:
  // member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  // private method
 private:
  void reserve_more_capacity(size_type);
  // public methods
 public:
  // default constructor (simplified syntax for assigning values to attributes)
  Vector() : m_size(0U), m_capacity(0U), arr(nullptr) {}
  // parametrized constructor for fixed size vector (explicit was used in order
  // to avoid automatic type conversion)
  explicit Vector(size_type n)
      : m_size(n), m_capacity(n), arr(n ? new T[n] : nullptr) {}
  // initializer list constructor (allows creating lists with initializer lists,
  // see main.cpp)
  Vector(std::initializer_list<value_type> const &items);
  // copy constructor with simplified syntax
  explicit Vector(const Vector &v) {
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    arr = v.arr;
  }
  // move constructor with simplified syntax
  Vector(Vector &&v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(v.arr) {
    v.arr = nullptr;
    v.m_size = 0;
  }

  // destructor
  ~Vector(){ delete[] arr; };
  // resize for rezerve
  Vector<value_type> &resize(size_type);
  // some method examples
  // size getter
  size_type size();
  // element accessor
  value_type at(size_type i);
  // append new element
  void push_back(value_type v);
  // index operator overload
  value_type &operator[](size_type);
  Vector<value_type> &operator=(const Vector<value_type> &);
};
}  // namespace s21

#endif
