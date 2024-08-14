#include "s21_vector.h"
/*
IMPLEMENTATION FILE
*/
using namespace s21;

/* Constructors */
template <typename value_type>
s21::Vector<value_type>::Vector(size_type n, const_reference value)
  : SequenceContainer<value_type>(n, value) {
}

template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> const &items) 
  : SequenceContainer<value_type>(std::initializer_list<value_type>(items)) {
  this->reserve(items.size());
};
// // many parameters
// template <typename value_type>
// template <typename... Args>
// s21::Vector<value_type>::Vector(Args... args)
//   : SequenceContainer<value_type>(sizeof...(args),
//   (sizeof...(args)
//   ? new value_type[sizeof...(args)]{args...} 
//   : nullptr)) {
// }

template <typename value_type>
void s21::Vector<value_type>::operator=(const Vector<value_type> &other) {
  this->SequenceContainer<value_type>::operator=(other);
}

// copy constructor
template <typename value_type>
s21::Vector<value_type>::Vector(const Vector<value_type> &v)
  : SequenceContainer<value_type>(v) {
}

// move constructor
template <typename value_type>
s21::Vector<value_type>::Vector(Vector<value_type> &&v)
  : SequenceContainer<value_type>(v.size(), *v.begin()) {
}

// reserve capacity
template <typename value_type>
void s21::Vector<value_type>::reserve(size_type n) {
  this->resize(n, value_type());
}

template <typename value_type>
value_type s21::Vector<value_type>::at(size_type i) {
  return this->operator[](i);
}

template <typename value_type>
value_type &s21::Vector<value_type>::operator[](size_type n) {
  if (n >= this->size() || n <= 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  iterator it = this->begin() + n;
  return (reference)*it;
}

template <typename value_type>
const value_type &s21::Vector<value_type>::operator[](size_type n) const {
  if (n >= this->size() || n <= 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  const_iterator it = this->cbegin() + n;
  return (const_reference)*it;
}

// externalizing template instances for correct linking, feel free to find more
// information
template class s21::Vector<int>;
template class s21::Vector<double>;
template class s21::Vector<std::string>;
// template class s21::Vector<s21::Vector<int>>;
// template class s21::Vector<s21::Vector<int>*>;