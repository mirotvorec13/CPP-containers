#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <exception>
#include <initializer_list>
// #include <iostream>

#include "base_sequence_cont.h"

/*
HEADER FILE
*/

// Test vector class with some basic example operations and concepts
namespace s21 {
template <class T>
class Vector : public Base<T> {
	private:
  size_t m_size;
	size_t m_capacity;
	T *arr;

  T *init(size_t n);
	void reserve_more_capacity(size_t);
 	public:
  // member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  using ptr = Base<T>;

  // default construct
	constexpr Vector() noexcept : Base<value_type>(), m_size(0U), m_capacity(0U), arr(nullptr) {}
  // copy constructor
  Vector(const Vector &);
  // move constructor
  Vector(Vector<value_type> &&);
  // construct with size and value (or size and value=default)
  Vector(size_type n, const_reference ref = value_type());
  // many parameters initializer list
  Vector(std::initializer_list<value_type> const &items);

  // destructor
  ~Vector() { delete[] arr; }


  void resize(size_type);
	void resize(size_type, const_reference);
  
  // constexpr size_type capacity() const { return this->m_capacity; }
	size_type capacity() { return m_capacity; }
  void reserve(size_type n) { reserve_more_capacity(n); }
  
  // push and delete
  iterator insert(const_iterator, const_reference);
	iterator insert(const_iterator, size_type, const_reference);
	template <typename IT>
	iterator insert(const_iterator, IT *, IT*);
  iterator erase(iterator);
	iterator erase(iterator, iterator);
	void push_back(const_reference);
	value_type pop_back();

  // element access
  reference at(size_type);
  const_reference at(size_type) const;

  // operator overload
  void operator=(const Vector<value_type> &other);
  reference operator[](size_type);
  const_reference operator[](size_type) const;
  void clear();

};

}  // namespace s21

#include "s21_vector.cpp"

#endif
