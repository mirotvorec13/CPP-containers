#ifndef S21_DEQUE_H
#define S21_DEQUE_H

#include <exception>
#include <initializer_list>
#include <iostream>

#include "base_sequence_cont.h"

namespace s21 {

template <class _E>
struct Node : public Base<_E> {
  public:
    Node *next_ = nullptr;
    Node *prev_ = nullptr;
  private:
    _E data_ = _E();
    Node<_E> *init();
  public:
  typedef Node<_E> *iterator;
  typedef _E &reference;
  typedef const _E &const_reference;
  typedef _E value_type;
  constexpr Node() noexcept : Base<value_type>(), next_(nullptr), prev_(nullptr), data_(_E()) {}
  
  Node(reference val) {
    next_ = nullptr;
    prev_ = nullptr;
    data_ = val;
  }
  Node(const_reference val) {
    next_ = nullptr;
    prev_ = nullptr;
    data_ = val;
  }

  ~Node() { delete Node(); }
  // operator Node<value_type>*() { std::cout << "notthis  --" << data_ << std::endl; return data_; }
  operator value_type*() { std::cout << "this  --" << &data_ << std::endl; return &data_; }
  // value_type operator*() { return data_; }
  // Node<value_type> &operator=(Node<_E> &val) {
  //   next_ = nullptr;
  //   prev_ = nullptr;
  //   data_ = *val;
  //   return *this;
  // }
  Node<value_type> *get_next() { return next_; }
  Node<value_type> *get_prev() { return prev_; }
  value_type get_data() { return data_; }
  // operator++
  iterator operator++() { return next_; }
  iterator operator--() { return prev_; }
  // void operator=(const_reference val)
  // copy construct
  void operator=(const Node<_E> &other) {
    next_ = other.next_;
    prev_ = other.prev_;
    data_ = other.data_;
  };
  void push_back(value_type);

  void operator=(value_type val) {
    this->data_ = val;
  }

  // iterator operator*() { return Data; }
};

}

namespace s21 {
template <class T>
class Deque : public Node<T> {
  private:
  T *head;
  T *tail;

  public:
  // member types
  using iterator = Node<T> *;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using const_iterator = const T *;
  using size_type = size_t;

  // def const
  Deque() : Base<Node<T>>() {}
  // copy constructor
  Deque(const Deque<value_type> &other)
    : Base<Node<value_type>>(other) {}
  // move
  Deque(Deque<value_type> &&other)
    : Base<Node<value_type>>(other){}
  Deque(size_type, const_reference = value_type());
  // init list
  Deque(std::initializer_list<value_type> const &items)
    : Base<Node<value_type>>(items){};
  // destructor
  ~Deque(){};

  void operator=(const Deque<value_type> &);

  // operator Node<T>*() : Node<value_type>::operator*() {}
  // void push_front(reference);
  // void pop_front();
  reference operator[](size_type);
  const_reference operator[](size_type) const;

};
}

#include "s21_deque.cpp"

#endif