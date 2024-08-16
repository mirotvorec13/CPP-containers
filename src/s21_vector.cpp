#include "s21_vector.h"
/*
IMPLEMENTATION FILE
*/
using namespace s21;

// copy constructor
template <typename value_type>
s21::Vector<value_type>::Vector(const Vector<value_type> &other)
    : SequenceContainer<value_type>(other) {}

// move constructor
template <typename value_type>
s21::Vector<value_type>::Vector(Vector<value_type> &&other)
    : SequenceContainer<value_type>(other) {}

// operator =
template <typename value_type>
void s21::Vector<value_type>::operator=(const Vector<value_type> &other) {
  SequenceContainer<value_type>::operator=(other);
}

// at
template <typename value_type>
value_type &s21::Vector<value_type>::at(size_type i) {
  return *(this->begin() + i);
}

// at const version
template <typename value_type>
const value_type &s21::Vector<value_type>::at(size_type i) const {
  return *(this->cbegin() + i);
}

// index operator overload
template <typename value_type>
value_type &s21::Vector<value_type>::operator[](size_type n) {
  if (n >= this->size()) {
    throw std::out_of_range("Incorrect input, index is out of range----");
  }
  return this->begin()[n];
}

// index operator overload
template <typename value_type>
const value_type &s21::Vector<value_type>::operator[](size_type n) const {
  if (n >= this->size() || n <= 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return this->cbegin()[n];
}

// externalizing template instances for correct linking, feel free to find more
// information
template class s21::Vector<int>;
template class s21::Vector<double>;
template class s21::Vector<std::string>;
template class s21::Vector<s21::Vector<int>>;
template class s21::Vector<s21::Vector<int> *>;