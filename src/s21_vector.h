#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <exception>
#include <initializer_list>
#include <iostream>

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
  Vector() : SequenceContainer<value_type>() {}
  // copy constructor
  Vector(const Vector<value_type> &);
  // move constructor
  Vector(Vector<value_type> &&);
  // parametrized constructor for fixed size vector (explicit was used in order
  // to avoid automatic type conversion)
  Vector(size_type n, const_reference ref = value_type())
      : SequenceContainer<value_type>(n, ref){};
  // many parameters initializer list
  Vector(std::initializer_list<value_type> const &items)
      : SequenceContainer<value_type>(items){};

  size_type capacity() { return this->_M_capacity; }
  void reserve(size_type n) { this->resize(n); }
  // destructor
  ~Vector(){};

  // element access
  value_type &at(size_type i);
  const value_type &at(size_type i) const;

  // operator overload
  void operator=(const Vector<value_type> &other);
  reference operator[](size_type);
  const_reference operator[](size_type) const;
  // iterator operator*() { return this->begin(); };
  // Vector<value_type> &operator=(const Vector<value_type> &);
};
}  // namespace s21

#include "s21_vector.cpp"

#endif
