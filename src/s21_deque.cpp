#include "s21_deque.h"

namespace s21 {
template <typename value_type>
Node<value_type> *Node<value_type>::init() {
  Node<value_type> *node = new Node<value_type>;
  return node;
}

template <typename value_type>
Deque<value_type>::Deque(size_type n, const_reference ref)
  : Node<value_type>() {
  
  this->head = this->begin();
  this->tail = this->end();
  for (size_type i = 0; i < n; ++i) {
    push_back(ref);
  }
}

template <typename value_type>
void Deque<value_type>::operator=(const Deque<value_type> &other) {
  
}

template <typename value_type>
value_type &Deque<value_type>::operator[](size_type n) {
  if (n >= this->size()) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return *(this->begin() + n);
}

template <typename value_type>
const value_type &Deque<value_type>::operator[](size_type n) const {
  if (n >= this->size() || n <= 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return *(this->cbegin() + n);
}

template <typename value_type>
void Node<value_type>::push_back(value_type val) {
  // iterator it = this->end();
  Node<value_type> *node = init();
  if (this->end() == this->begin()) {
    node->operator=(val);
    this->_M_len++;
  } else {
    node->prev_ = this->get_prev();
    node->operator=(val);
    this->_M_len++;
  }
}

// template <typename value_type>
// void Deque<value_type>::push_front(reference ref) {
//   this->insert(begin(), ref);
// }

// template <typename value_type>
// void Deque<value_type>::pop_front() {
//   erase(this->begin());
// }

}