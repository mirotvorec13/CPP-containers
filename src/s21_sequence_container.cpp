#include "s21_sequence_container.h"

using namespace s21;

/* reserve more capacity */
template <typename value_type>
void s21::SequenceContainer<value_type>::reserve_more_capacity(size_type n) {
  value_type *buff = new value_type[n];
  for (size_type i = 0; i < this->size(); ++i) {
    buff[i] = *(this->begin() + i);
  }
  this->resize(n, value_type());
  for (size_type i = 0; i < this->size(); ++i) {
    this->push_back(buff[i]);
  }
  delete[] buff;
}

template <typename T>
s21::SequenceContainer<T>::SequenceContainer(std::initializer_list<value_type> const &items) {
  this->resize(items.size(), value_type());
  for (auto it = items.begin(); it != items.end(); it++) {
    this->_M_array[this->_M_len++] = *it;
  }
};

// iterators 
template <class _Tp>
constexpr const _Tp* begin(SequenceContainer<_Tp> __ils) noexcept {
  return __ils.begin();
}
template <class _Tp>
constexpr const _Tp* end(SequenceContainer<_Tp> __ils) noexcept {
  return __ils.end();
}

/// @brief
// construct copy
/// @param other
template <class value_type>
s21::SequenceContainer<value_type>::SequenceContainer(const SequenceContainer<value_type> &other) {
  this->_M_len = other._M_len;
  this->_M_array = other._M_array;
}

// constructor with allocated memory for some pointer
template <class value_type>
s21::SequenceContainer<value_type>::SequenceContainer(size_type n, const_reference ref) {
  this->reserve_more_capacity(n);
  this->_M_len = 0;
  for (size_type i = 0; i < n; ++i) {
    this->push_back(ref);
  }
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
s21::SequenceContainer<value_type> &s21::SequenceContainer<value_type>::operator=(const SequenceContainer<value_type> &other) {
  this->_M_len = other._M_len;
  if (this->_M_array != other._M_array) {
    delete[] this->_M_array;
    resize(other._M_len, value_type());
  }
  for (size_type i = 0; i < other._M_len; ++i) {
    this->_M_array[i] = other._M_array[i];
  }
  return *this;
}

template <class value_type>
void s21::SequenceContainer<value_type>::resize(size_type n, value_type v) {
  for (size_type i = this->_M_len; i < n && i < this->size(); ++i) {
    push_back(v);
  }
}

template <typename value_type>
value_type &s21::SequenceContainer<value_type>::front() {
  return this->_M_array[0];
}

// insert new element at position
// template <class value_type>
// void s21::SequenceContainer<value_type>::insert(const_iterator it, size_type n, const value_type &ref) {
//   for (size_t i = 0; i < n; ++i) {
//     insert(it, ref);
//   }
// }

// template <class value_type>
// template <class IT>
// void s21::SequenceContainer<value_type>::insert(const_iterator pos, IT first, IT last) {
//   while (first != last) {
//       this->insert(pos, *first);
//       ++first;
//   }
// }
// template <class _Tp>
// constexpr const _Tp* begin(SequenceContainer<_Tp> __ils) noexcept {
//   return __ils.begin();
// }

template <typename value_type>
void s21::SequenceContainer<value_type>::push_back(const_reference v) {
  this->_M_array[this->_M_len++] = v;
}

template <typename value_type>
value_type s21::SequenceContainer<value_type>::pop_back() {
  value_type temp = this->_M_array[--this->_M_len];
  this->_M_array[this->_M_len] = value_type();
  return temp;
}

// namespace s21
