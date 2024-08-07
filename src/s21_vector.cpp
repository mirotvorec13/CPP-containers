#include "s21_vector.h"
/*
IMPLEMENTATION FILE
*/
using namespace s21;
template <typename value_type>
void s21::Vector<value_type>::reserve_more_capacity(size_type size) {
  if (size > m_capacity) {
    value_type *buff = new value_type[size];
    for (size_t i = 0; i < m_size; ++i) buff[i] = std::move(arr[i]);
    delete[] arr;
    arr = buff;
    m_capacity = size;
  }
}

// initializer list constructor (allows creating lists with initializer lists,
// see
template <typename value_type>
s21::Vector<value_type>::Vector(
    std::initializer_list<value_type> const &items) {
  arr = new value_type[items.size()];
  int i = 0;
  for (auto it = items.begin(); it != items.end(); it++) {
    arr[i] = *it;
    i++;
  }
  m_size = items.size();
  m_capacity = items.size();
};

template <typename value_type>
s21::Vector<value_type> &s21::Vector<value_type>::resize(size_type size) {
  if (m_size != size) {
    if (m_capacity < size) {
      this->reserve_more_capacity(size);
    } else if (m_capacity > size && size != 0) {
      Vector<value_type> tmp(size);
      for (size_t i = 0; i < m_size; i++) {
        tmp.arr[i] = arr[i];
      }
      delete[] arr;
      m_capacity = tmp.m_capacity;
      m_size = tmp.m_size;
      arr = tmp.arr;
    }
  }
  return *this;
}

template <typename value_type>
size_t s21::Vector<value_type>::size() {
  return m_size;
}

template <typename value_type>
value_type s21::Vector<value_type>::at(size_type i) {
  return arr[i];
}

template <typename value_type>
void s21::Vector<value_type>::push_back(value_type v) {
  if (m_size == m_capacity) {
    reserve_more_capacity(m_size * 2);
  }
  arr[m_size++] = v;
}
// operators
template <typename value_type>
value_type &s21::Vector<value_type>::operator[](size_type n) {
  if (n >= m_size || n <= 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return arr[n];
}

template <typename value_type>
s21::Vector<value_type> &s21::Vector<value_type>::operator=(
    const Vector<value_type> &other) {
  s21::Vector<value_type> temp(other.m_capacity);
  if (arr) {
    delete[] arr;
  }
  for (size_t i = 0; i < other.m_size; ++i) {
    temp.arr[i] = other.arr[i];
  }
  m_size = temp.m_size;
  m_capacity = temp.m_capacity;
  arr = temp.arr;
  return *this;
}

// externalizing template instances for correct linking, feel free to find more
// information
template class s21::Vector<int>;
