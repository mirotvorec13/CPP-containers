#ifndef S21_DEQUE_H
#define S21_DEQUE_H

#include <exception>
#include <initializer_list>
#include <iostream>

#include "base_deque_iterator.h"

namespace s21 {

// class Node
// template <class _E>
// struct Node {
//   Node *next_;
//   Node *prev_;
//   _E data_;

//   // construct
//   Node(Node *next = nullptr, Node *prev = nullptr,
//     const _E &val = _E())
//     : Base<_E>(), next_(next), prev_(prev), data_(val) { }

  // // operators
  // operator value_type*() { return &data_; }
  // // operator Node<value_type>*() { return &data_; }
  // // Node<value_type> &operator=(Node<value_type> &node) {
  // //   this->next_ = node.next_;
  // //   this->prev_ = node.prev_;
  // //   this->data_ = node.data_;
  // //   return this;
  // // }

  // Node<value_type> &operator=(value_type &val) {
  //   this->data_ = val;
  //   return *this;
  // }

  // get
  // Node<value_type> *get_next() { return next_; }
  // Node<value_type> *get_prev() { return prev_; }
  // value_type get_data() { return data_; }

  // // set
  // void set_next(Node<value_type> *node) { this->next_ = node; }
  // void set_prev(Node<value_type> *node) { this->prev_ = node; }
  // void set_data(value_type &val) { data_ = val; }
  // copy construct
//   void operator=(Node<_E> &other) {
//     next_ = other.next_;
//     prev_ = other.prev_;
//     data_ = other.data_;
//   };

//   void operator=(const _E &val) {
//     this->data_ = val;
//   }
// };


template <typename E>
struct Node {
  E data_;
  Node *next_;
  Node *prev_;
  // construct
  Node &init() { return Node<E>; }
  Node(const E &val = E(), Node *next = nullptr, Node *prev = nullptr)
    : Base<Node<E>>(0U, init()), next_(next), prev_(prev), data_(val) { }
  
  operator Node<E>*() { return &data_; }
  // operator E*() { return &data_; }
};

// class deque
template <class T>
class Deque : Node<T>, Base<Node<T> {
  public:
  using iterator = Node<T> *;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using const_iterator = const T *;
  using size_type = size_t;

  // def const
  Deque() : Node<value_type>(), head(nullptr), tail(nullptr) {}
  // copy constructor
  // Deque(const Deque<value_type> &other)
  //   : Node(other) {}
  // // move
  // Deque(Deque<value_type> &&other)
  //   :Node(other){}
  Deque(size_type, const_reference = value_type());
  // init list
  // Deque(std::initializer_list<value_type> const &items)
  //   : Node(items){};
  // // destructor
  ~Deque(){};

  void operator=(const Deque<value_type> &);
  // operator ++ --
  iterator operator++() { return this->get_next(); }
  iterator operator--() { return this->get_prev(); }
  void push_back(const_reference);
  // operator Node<E>*() { return &data_; }
  // operator Node<T>*() : Node<value_type>::operator*() {}
  // void push_front(reference);
  // void pop_front();

};
}

#include "s21_list.tpp"

#endif