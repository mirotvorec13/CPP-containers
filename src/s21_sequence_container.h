#ifndef _S21_SEQUENCE_CONTAINER_H
#define _S21_SEQUENCE_CONTAINER_H

#include <exception>
#include <initializer_list>
// #include "s21_vector.h"

namespace s21 {
template <class _E>
class SequenceContainer {
 public:
  typedef _E value_type;
  typedef const _E& reference;
  typedef const _E& const_reference;
  typedef size_t size_type;
  typedef _E* iterator;
  typedef const _E* const_iterator;
  typedef const _E* reverse_iterator;

 private:
  size_type _M_len;
  iterator _M_array;
  void reserve_more_capacity(size_type);
 public:

  // default constructor
  constexpr SequenceContainer() noexcept : _M_len(0U), _M_array(0U) { }
  // constructor with initializer list
  SequenceContainer(const SequenceContainer<value_type>&);
  // constructor with allocated memory for some pointer
  SequenceContainer(size_type,  const_reference = value_type());
  // many parameters
  // template <class... Args>
  // SequenceContainer(Args... args);
  SequenceContainer(std::initializer_list<value_type> const &items);
  // destructor
  ~SequenceContainer() { delete[] _M_array; };

  SequenceContainer<value_type> &operator=(const SequenceContainer<value_type> &other);

  // iterators
  iterator begin() noexcept { return _M_array; }
  iterator end() noexcept { return _M_array + _M_len; }
  const_iterator cbegin() const noexcept { return _M_array; }
  const_iterator cend() const noexcept { return _M_array + _M_len; }

  // size
  constexpr size_type size() const noexcept { return cend() - cbegin(); }
  void resize(size_type, value_type);

  bool empty() { return _M_len == 0; };
  // void insert(const_iterator, reference); // single element
  // void insert(const_iterator, size_type, reference); // range
  // template <class IT>
  // void insert<IT>(const_iterator, IT, IT); // range with iterators
  // void erase(iterator); // single element
  // void erase(iterator, iterator); // range
  void push_back(const_reference);
  // template <class T>
  // void push_back(T &);
  value_type pop_back();
  value_type &front();
  // reference back();
};
} // namespace s21

#include "s21_sequence_container.cpp"

#endif
