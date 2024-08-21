#ifndef S21_DEQUE_H
#define S21_DEQUE_H

#include <exception>
#include <initializer_list>
#include <iostream>

#include "s21_sequence_container.h"

template <class _E>
struct Node {
  private:
  Node *next_ = nullptr;
  Node *prev_ = nullptr;
  _E data_ = _E();
  public:
  typedef Node<_E> &iterator;
  typedef _E &reference;
  typedef const _E &const_reference;
  typedef _E value_type;
  constexpr Node() noexcept : next_(nullptr), prev_(nullptr), data_(_E()) {}
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
  // operator Node<value_type>*() { std::cout << "notthis  --" << data_ << std::endl; return data_; }
  operator value_type*() { std::cout << "this  --" << &data_ << std::endl; return &data_; }
  // value_type operator*() { return data_; }
  Node<value_type> &operator=(Node<_E> &val) {
    next_ = nullptr;
    prev_ = nullptr;
    data_ = *val;
    return *this;
  }
  value_type get_data() { return data_; }
  // operator++
  iterator operator++(_E) { return next_; }
  // void operator=(const_reference val)
  // copy construct
  Node<_E> &operator=(const Node<_E> &other) {
    next_ = other.next_;
    prev_ = other.prev_;
    data_ = other.data_;
    return *this;
  };

  value_type operator=(value_type val) {
    this->data_ = val;
    return data_;
  }
  // iterator operator*() { return Data; }
};

namespace s21 {
template <class T>
class Deque : public SequenceContainer<Node<T>> {
  public:
  
  private:
  // Node *head;
  // Node *tail;
  public:
  // member types
  using iterator = Node<T> *;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using const_iterator = const T *;
  using size_type = size_t;
  // using iterator = T **;

  // def const
  Deque() : SequenceContainer<Node<T>>() {}
  // copy constructor
  Deque(const Deque<value_type> &other)
    : SequenceContainer<Node<value_type>>(other) {}
  // move
  Deque(Deque<value_type> &&other)
    : SequenceContainer<Node<value_type>>(other){}
  Deque(size_type n, const_reference ref = value_type())
    : SequenceContainer<Node<value_type>>(n, ref) {};
  // init list
  Deque(std::initializer_list<value_type> const &items)
    : SequenceContainer<Node<value_type>>(items){};
  // destructor
  ~Deque(){};

  void operator=(const Deque<value_type> &other);
  // operator Node<T>*() : Node<value_type>::operator*() {}
  // void push_front(reference);
  // void pop_front();
  reference operator[](size_type);
  const_reference operator[](size_type) const;

};
}

#include "s21_deque.cpp"

#endif