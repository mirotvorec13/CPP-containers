#include "s21_deque.h"

using namespace s21;

template <typename value_type>
void s21::Deque<value_type>::operator=(const Deque<value_type> &other) {
  SequenceContainer<value_type>::operator=(other);
}

template <typename value_type>
value_type &s21::Deque<value_type>::operator[](size_type n) {
  if (n >= this->size()) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return *(this->begin() + n);
}

template <typename value_type>
const value_type &s21::Deque<value_type>::operator[](size_type n) const {
  if (n >= this->size() || n <= 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return *(this->cbegin() + n);
}

// template <typename value_type>
// void s21::Deque<value_type>::push_front(reference ref) {
//   this->insert(begin(), ref);
// }

// template <typename value_type>
// void s21::Deque<value_type>::pop_front() {
//   erase(this->begin());
// }