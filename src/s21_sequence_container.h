#ifndef _S21_SEQUENCE_CONTAINER_H
#define _S21_SEQUENCE_CONTAINER_H

#include "s21_vector.h"
#include "s21_pair.h"
#include "s21_list.h"

namespace s21 {
template <class _E>
class SequenceContainer {
 public:
  typedef _E value_type;
  typedef const _E& reference;
  typedef const _E& const_referene;
  typedef size_t size_type;
  typedef const _E* iterator;
  typedef const _E* const_iterator;
  typedef const _E* reverse_iterator;

 private:
  size_type _M_len;
  iterator _M_array;

  constexpr SequenceContainer(const_iterator __a, size_type __l) noexcept
      : _M_array(__a), _M_len(__l) {}

 public:
  constexpr SequenceContainer() noexcept : _M_array(0), _M_len(0) {}

  constexpr SequenceContainer(SequenceContainer& other) {
    if (this != &other) {
      this = other;
    }
  };
  SequenceContainer(size_type, _E& = _E()){};

  SequenceContainer<value_type>& operator=(
      SequenceContainer<value_type>& other);

  constexpr const_iterator begin() const noexcept { return _M_array; }
  constexpr const_iterator end() const noexcept { return _M_array + _M_len; }
  constexpr reverse_iterator rbegin() const noexcept {
    return _M_array + _M_len;
  }
  constexpr reverse_iterator rend() const noexcept { return _M_array; }

  constexpr size_type size() const noexcept { return _M_len; }
  void resize(size_type n, value_type obj){

  };

  // bool empty();
  // insert(iterator, T &);
  // insert(iterator, size_type, T &);
  // insert<lT>(iterator, lT, lT);
  // erase(iterator);
  // erase(iterator, iterator);
  // void push_back(T &);
  // pop_back();
  // T & front();
  // T & back();
};
template <class _Tp>
constexpr const _Tp* begin(SequenceContainer<_Tp> __ils) noexcept {
  return __ils.begin();
}

template <class _Tp>
constexpr const _Tp* end(SequenceContainer<_Tp> __ils) noexcept {
  return __ils.end();
}
}  // namespace s21

#endif
