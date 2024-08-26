#include "s21_sequence_container.h"

using namespace s21;

// construct copy
template <class value_type>
s21::SequenceContainer<value_type>::SequenceContainer(
    const SequenceContainer<value_type> &other) {
  this->_M_len = 0;
  _M_array = reserve(other.capacity());
  for (size_type i = 0; i < other._M_len; ++i) {
    this->_M_array[i] = other._M_array[i];
    this->_M_len++;
  }
}

// move constructor
template <class value_type>
s21::SequenceContainer<value_type>::SequenceContainer(
    SequenceContainer<value_type> &&other) noexcept {
  reserve(other.capacity());
  SequenceContainer<value_type>::operator=(std::move(other));
  delete[] other._M_array;
  other._M_len = 0;
}

// constructor with allocated memory for some value
template <class value_type>
s21::SequenceContainer<value_type>::SequenceContainer(size_type n,
                                                      const_reference ref) {
  _M_len = 0;
  _M_array = reserve(n);
  for (size_type i = 0; i < n; ++i) {
    this->push_back(ref);
  }
}

// constructor initializer list
template <typename T>
s21::SequenceContainer<T>::SequenceContainer(
    std::initializer_list<value_type> const &items) {
  this->_M_len = 0;
  _M_array = reserve(items.size());
  for (auto it = items.begin(); it != items.end(); it++) {
    this->_M_array[this->_M_len] = *it;
    this->_M_len++;
  }
};

// iterators
template <class _Tp>
constexpr const _Tp *begin(SequenceContainer<_Tp> __ils) noexcept {
  return __ils.begin();
}
template <class _Tp>
constexpr const _Tp *end(SequenceContainer<_Tp> __ils) noexcept {
  return __ils.end();
}

// many parameters
// template <typename value_type>
// template <typename... Args>
// s21::SequenceContainer<value_type>::SequenceContainer(Args... args) {
//   this->_M_array = (sizeof...(args)
//   ? new value_type[sizeof...(args)]{args...}
//   : nullptr);
//   this->_M_len = sizeof...(args);
// }

// copy assignment
template <class value_type>
s21::SequenceContainer<value_type> &
s21::SequenceContainer<value_type>::operator=(
    const SequenceContainer<value_type> &other) {
  clear();
  if (this != &other) {
    resize(other._M_len);
    for (size_type i = 0; i < other._M_len; ++i) {
      push_back(other._M_array[i]);
    }
  }
  return *this;
}

// clear
template <class value_type>
void s21::SequenceContainer<value_type>::clear() {
  while (this->_M_len > 0) {
    pop_back();
  }
}

// resize with value
template <class value_type>
void s21::SequenceContainer<value_type>::resize(size_type n,
                                                const_reference v) {
  resize(n);
  for (size_type i = this->_M_len; i < n; ++i) {
    push_back(v);
  }
}

// resize without value
template <class value_type>
void s21::SequenceContainer<value_type>::resize(size_type n) {
  if (n > this->capacity()) {
    _M_array = reserve(n);
  } else if (n < this->_M_len) {
    while (n < this->_M_len) {
      pop_back();
    }
  }
}

// first element
template <typename value_type>
value_type &s21::SequenceContainer<value_type>::front() {
  return this->_M_array[0];
}

// last element
template <typename value_type>
value_type &s21::SequenceContainer<value_type>::back() {
  return this->_M_array[this->_M_len - 1];
}

// push_back
template <typename value_type>
void s21::SequenceContainer<value_type>::push_back(const_reference v) {
  if (this->_M_len == this->capacity()) {
    _M_array = reserve(this->_M_len * 2);
  }
  _M_array[_M_len] = v;
  _M_len++;
}

// pop_back
template <typename value_type>
value_type s21::SequenceContainer<value_type>::pop_back() {
  _M_len--;
  value_type temp = _M_array[_M_len];
  _M_array[_M_len] = value_type();
  return temp;
}

// insert new element at position
template <typename value_type>
value_type *s21::SequenceContainer<value_type>::insert(const_iterator pos, const_reference val) {
  size_type t = 0;
  size_type t_pos = (this->cend() - pos);
  iterator it = new value_type[_M_len + 1];
  for (iterator i = it, arr = _M_array; i < it + _M_len + 1; ++i, ++arr) {
    if (t == _M_len - t_pos) {
      *i = val;
      ++i;
      *i = *arr;
      ++t;
    }
    *i = *arr;
    if (t < _M_len - t_pos) {
      ++t;
    }
  }
  if (capacity() < _M_len + 1) {
    this- _M_array = reserve(_M_len * 2);
  }
  _M_len++;
  for (iterator i = it, iter = _M_array; i < it + _M_len; ++i, ++iter) {
    *iter = *i;
  }
  delete[] it;
  iterator arr = _M_array;

  return arr + _M_len - t_pos - 1;
}

// insert new element at position
template <class value_type>
value_type *s21::SequenceContainer<value_type>::insert(const_iterator pos, size_type
n, const_reference val) {
  iterator it;
  for (size_type i = 0; i < n; ++i) {
    it = insert(pos, val);
  }
  return it;
}

// insert range of elements
template <class value_type>
template <class IT>
value_type *s21::SequenceContainer<value_type>::insert(const_iterator pos, IT *first, IT *last) {
  iterator it;
  while (first != last) {
    it = insert(pos, *--last);
  }
  return it;
}

// erase element
template <class value_type>
value_type *s21::SequenceContainer<value_type>::erase(iterator pos) {
  // size_type t_pos = (this->end() - pos) - 1;
  iterator start = this->begin();
  while (start != pos) {
    start++;
  }

  for (auto it = pos; it < this->end();) {
    *start++ = *++it;
  }
  this->_M_len--;
  return pos;
}

// erase range of elements
template <class value_type>
value_type *s21::SequenceContainer<value_type>::erase(iterator first, iterator last) {
  while (first != last) {
    erase(--last);
  }
  return last;
}