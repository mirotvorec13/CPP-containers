#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <iostream>
#include <exception>
#include <initializer_list>

#include "s21_sequence_container.h"
/*
HEADER FILE
*/


// Test vector class with some basic example operations and concepts
namespace s21 {
template <class T>
class Vector : public SequenceContainer<T> {
 public:
  // member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  
  // default constructor
  Vector() : SequenceContainer<value_type>() { }
  // parametrized constructor for fixed size vector (explicit was used in order
  // to avoid automatic type conversion)
  Vector(size_type, const_reference = value_type());
  // many parameters
  Vector(std::initializer_list<value_type> const &items);
  // template <class... Args>
  // Vector(Args... args) : SequenceContainer<value_type>(args...) { };
  // copy constructor
  Vector(const Vector<value_type> &v);
  // move constructor
  Vector(Vector<value_type> &&v);

  size_type capacity() { return this->size(); }
  void reserve(size_type n);
  // destructor
  ~Vector() { };
  // resize for rezerve
  // some method examples
  // size getter
  // size_type size();
  // element accessor
  value_type at(size_type i);
  // append new element
  // void push_back(value_type v);
  // index operator overload
  void operator=(const Vector<value_type> &);
  reference operator[](size_type);
  const_reference operator[](size_type) const;
  iterator operator*() { return this->begin(); };
  // Vector<value_type> &operator=(const Vector<value_type> &);
};
}  // namespace s21

#include "s21_vector.cpp"

#endif
