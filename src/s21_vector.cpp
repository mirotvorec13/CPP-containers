#include "s21_vector.h"

/*
IMPLEMENTATION FILE
*/
namespace s21 {

template <typename value_type>
value_type *Vector<value_type>::init(size_t n) {
  m_size = 0U;
  arr = n ? new value_type[n] : nullptr;
  m_capacity = n;
  return arr;
}

/* reserve more capacity */
template <typename value_type>
void Vector<value_type>::reserve_more_capacity(size_t n) {
  value_type *buff = new value_type[n];
  for (size_type i = 0; i < this->m_size; ++i) {
    buff[i] = this->at(i);
  }
  delete[] arr;
  arr = buff;
  m_capacity = n;
  this->set_ptr(arr);
}

template <typename value_type>
Vector<value_type>::Vector(const Vector &other) 
  : Base<value_type>(other.size(), init(other.size())) {
  *this = other;
}

template <typename value_type>
Vector<value_type>::Vector(size_type n, const_reference ref)
  : Base<value_type>(n, init(n)) {
  for (auto it = this->begin(); it < this->end(); ++it) {
    *it = ref;
    ++m_size;
  }
}

template <typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> const &items) 
 : Base<value_type>(items.size(), init(items.size())) {
  for (auto it = this->begin(), it_items = items.begin(); it != this->end();) {
    *it++ = *it_items++;
    ++m_size;
  }
}

// move constructor
template <typename value_type>
Vector<value_type>::Vector(Vector<value_type> &&other) 
  : Base<value_type>() {
  this->m_size = other.m_size;
  this->m_capacity = other.m_capacity;
  this->arr = other.arr;
  this->_M_len = other._M_len;
  this->set_ptr(this->arr);
  other.m_size = 0U;
  other.m_capacity = 0U;
  other.arr = nullptr;
}

// resize
template <typename value_type>
void Vector<value_type>::resize(size_type n) {
  if (n == m_size) {
    return;
  }
  if (n < m_size) {
    while (n < m_size) {
      pop_back();
    }
  } else if (n > m_capacity) {
    reserve(n);
  }
}


template <typename value_type>
void Vector<value_type>::resize(size_type n, const_reference ref) {
  resize(n);
  size_type it = n - m_size;
  for (size_type i = 0; i < it; ++i) {
    this->push_back(ref);
  }
}

// insert new element at position
template <typename value_type>
value_type *Vector<value_type>::insert(const_iterator pos, const_reference val) {
  size_type t = 0;
  size_type start = (pos - this->cbegin());
  size_type t_pos = (this->cend() - pos);
  const_iterator it_pos = pos;
  iterator it = new value_type[t_pos + 1]; // 1 element
  it[0] = val;
  for (size_type i = 1; i < t_pos + 1; ++i) {
    it[i] = *it_pos++;
  }
  // std::cout << std::endl;
  resize(m_size + 1); // 1 element
  this->_M_len = ++m_size;
  for (iterator it_ptr = this->begin(); it_ptr < this->end(); ++it_ptr) {
    while (t < start) {
      it_ptr++;
      t++;
    }
    *it_ptr = *it++;
  }
  return &arr[start];
}


// insert new element at position
template <typename value_type>
value_type *Vector<value_type>::insert(const_iterator pos, size_type
n, const_reference val) {
  iterator it;
  for (size_type i = 0; i < n; ++i) {
    it = insert(pos, val);
    pos = it;
  }
  return it;
}

// insert range of elements
template <typename value_type>
template <class IT>
value_type *Vector<value_type>::insert(const_iterator pos, IT *first, IT *last) {
  iterator it;
  while (first != last) {
    it = insert(pos, *--last);
    pos = it;
  }
  return it;
}

// erase element in vector
template <typename value_type>
value_type *Vector<value_type>::erase(iterator pos) {
  iterator start = this->begin();
  while (start != pos) {
    start++;
  }

  for (iterator it = pos; it < this->end();) {
    *start++ = *++it;
  }
  this->_M_len = --m_size;
  return pos;
}

// erase many elements in vector
template <typename value_type>
value_type *Vector<value_type>::erase(iterator first, iterator last) {
  while (first != last) {
    erase(--last);
  }
  return last;
}

// operator =
template <typename value_type>
void Vector<value_type>::operator=(const Vector<value_type> &other) {
  clear();
  if (this != &other) {
    resize(other.m_size);
    for (size_type i = 0; i < other.m_size; ++i) {
      push_back(other.arr[i]);
    }
  }
}

// at
template <typename value_type>
value_type &Vector<value_type>::at(size_type i) {
  return *(this->begin() + i);
}

// at const version
template <typename value_type>
const value_type &Vector<value_type>::at(size_type i) const {
  return *(this->cbegin() + i);
}

// push_back
template <typename value_type>
void Vector<value_type>::push_back(const_reference value) {
  if (m_size == m_capacity) {
    reserve(m_size + 1);
  }
  this->arr[this->m_size] = value;
  this->_M_len = ++m_size;
}

// pop_back
template <typename value_type>
value_type Vector<value_type>::pop_back() {
  this->_M_len--;
  m_size--;
  value_type temp = arr[this->m_size];
  arr[this->m_size] = value_type();
  return temp;
}

// index operator overload
template <typename value_type>
value_type &Vector<value_type>::operator[](size_type n) {
  if (n >= this->size()) {
    throw std::out_of_range("Incorrect input, index is out of range----");
  }
  return *(this->begin() + n);
}

// index operator overload
template <typename value_type>
const value_type &Vector<value_type>::operator[](size_type n) const {
  if (n >= this->size() || n <= 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return *(this->cbegin() + n);
}

template <typename value_type>
void Vector<value_type>::clear() {
  while (this->m_size > 0) {
    pop_back();
  }
}

} // namespace s21

// externalizing template instances for correct linking, feel free to find more
// information
template class s21::Vector<int>;
template class s21::Vector<double>;
template class s21::Vector<std::string>;
template class s21::Vector<s21::Vector<int>>;
template class s21::Vector<s21::Vector<int> *>;