#include "s21_list.h"

namespace s21 {

// template <typename value_type>
// Node<value_type> *Deque<value_type>::init() {
//   return new Node<value_type>;
// }


template <typename value_type>
Deque<value_type>::Deque(size_type n, const_reference val) 
  : Node<value_type>(), head(nullptr), tail(nullptr) {
  this->_M_len = 0;
  for (size_type i = 0; i < n; ++i) {
    this->push_back(val);
  }
}

template <typename value_type>
void Deque<value_type>::operator=(const Deque<value_type> &other) {
  
}

template <typename value_type>
void Deque<value_type>::push_back(const_reference val) {
  Node<value_type> *node = new Node<value_type>(nullptr, this->tail, val);
  if (this->tail) {
    this->tail->next_ = node;
  }
  this->tail = node;
  if (this->head == nullptr) {
    this->head = node;
  }
  this->_M_len++;
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