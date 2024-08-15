#include "s21_sequence_container.h"

using namespace s21;

/* reserve more capacity */
template <typename value_type>
void s21::SequenceContainer<value_type>::reserve_more_capacity(size_type n) {
  value_type *buff = new value_type[n];
  if (this->_M_len > 0) {
    for (size_type i = 0; i < this->_M_len; ++i) {
      buff[i] = this->_M_array[i];
    }
    delete[] this->_M_array;
    _M_array = buff;
  } else {
    _M_array = buff;
  }
  this->_M_capacity = n;
}

// construct copy
template <class value_type>
s21::SequenceContainer<value_type>::SequenceContainer(
    const SequenceContainer<value_type> &other) {
  this->_M_len = 0;
  reserve_more_capacity(other._M_capacity);
  for (size_type i = 0; i < other._M_len; ++i) {
    this->_M_array[i] = other._M_array[i];
    this->_M_len++;
  }
}

// move constructor
template <class value_type>
s21::SequenceContainer<value_type>::SequenceContainer(
    SequenceContainer<value_type> &&other) noexcept {
  reserve_more_capacity(other._M_capacity);
  SequenceContainer<value_type>::operator=(std::move(other));
  delete[] other._M_array;
  other._M_len = 0;
  other._M_capacity = 0;
}

// constructor with allocated memory for some value
template <class value_type>
s21::SequenceContainer<value_type>::SequenceContainer(size_type n,
                                                      const_reference ref) {
  _M_len = 0;
  this->reserve_more_capacity(n);
  for (size_type i = 0; i < n; ++i) {
    this->push_back(ref);
  }
}

// constructor initializer list
template <typename T>
s21::SequenceContainer<T>::SequenceContainer(
    std::initializer_list<value_type> const &items) {
  this->_M_len = 0;
  reserve_more_capacity(items.size());
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
  if (n > this->_M_capacity) {
    reserve_more_capacity(n);
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
  if (this->_M_len == this->_M_capacity) {
    reserve_more_capacity(this->_M_len * 2);
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
// template <class value_type>
// void s21::SequenceContainer<value_type>::insert(const_iterator it, size_type
// n, const value_type &ref) {
//   for (size_t i = 0; i < n; ++i) {
//     insert(it, ref);
//   }
// }

// template <class value_type>
// template <class IT>
// void s21::SequenceContainer<value_type>::insert(const_iterator pos, IT first,
// IT last) {
//   while (first != last) {
//       this->insert(pos, *first);
//       ++first;
//   }
// }
// template <class _Tp>
// constexpr const _Tp* begin(SequenceContainer<_Tp> __ils) noexcept {
//   return __ils.begin();
// }
// namespace s21
