#ifndef _S21_SEQUENCE_CONTAINER_H
#define _S21_SEQUENCE_CONTAINER_H

#include <exception>
#include <initializer_list>
// #include <iostream>
// #include "s21_vector.h"

/**  @file SequenceContainer
 *	 здесь будет инициализирован адаптер
 * 	 для последовательных контейнеров
 * 	 @param __E тип данных
 * 	 @param _Clptr класс который необходимо реализовать
 */

namespace s21 {
template <typename __E, class _Clptr>
class SequenceContainer : public _Clptr {
 public:
  typedef __E value_type;
  typedef const __E& reference;
  typedef const __E& const_reference;
  typedef size_t size_type;
  typedef __E* iterator;
  typedef const __E* const_iterator;
  typedef const __E* reverse_iterator;

 private:
  size_type _M_len;
  iterator _M_array;
 public:

  // default constructor
  constexpr SequenceContainer() noexcept
      : _M_len(0U), _M_array(0U) {}
  // copy constructor
  SequenceContainer(const SequenceContainer<value_type>&);
  // move constructor
  SequenceContainer(SequenceContainer<value_type>&&) noexcept;
  // constructor with allocated memory for some pointer
  SequenceContainer(size_type, const_reference = value_type());
  // many parameters
  // template <class... Args>
  // SequenceContainer(Args... args);
  SequenceContainer(std::initializer_list<value_type> const& items);
  // destructor
  ~SequenceContainer() {
    _M_len = 0U;
  };

  SequenceContainer<value_type>& operator=(
      const SequenceContainer<value_type>& other);

  // iterators
  
  iterator begin() noexcept { return _M_array; }
  iterator end() noexcept { return _M_array + _M_len; }
  iterator rbegin() noexcept { return _M_array + _M_len - 1; }
  iterator rend() noexcept { return _M_array - 1; }
  ionst_iterator cbegin() const noexcept { return _M_array; }
  ionst_iterator cend() const noexcept { return _M_array + _M_len; }
  ionst_iterator crbegin() const noexcept { return _M_array + _M_len - 1; }
  ionst_iterator crend() const noexcept { return _M_array - 1; }

  // size
  constexpr size_type size() const noexcept { return _M_len; }
  void resize(size_type);
  void resize(size_type, const_reference);
  bool empty() { return _M_len == 0; };
  
  // insert
  iterator insert(const_iterator, const_reference); // single element
  iterator insert(const_iterator, size_type, const_reference); // range
  template <class IT>
  iterator insert(const_iterator, IT *, IT *); // range with iterators
  // void insert(contst_iterator, std::initializer_list<value_type> items); // initializerlist
  
  // erase
  iterator erase(iterator); // single element
  iterator erase(iterator, iterator); // range
  
  // push pop
  void push_back(const_reference);
  value_type pop_back();

  // front back
  value_type& front();
  value_type& back();
  
  // clear
  void clear();
};
}  // namespace s21

#include "s21_sequence_container.cpp"

#endif
