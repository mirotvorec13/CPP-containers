#ifndef BASE_DEQUE_ITERATOR
#define BASE_DEQUE_ITERATOR

namespace s21 {
/// @brief класс для итераторов
/// @tparam _E - Node<T> 
template <class _E>
class Base {
  public:
    typedef size_t      size_type;
    typedef _E          value_type;
    typedef _E *        iterator;
    typedef const _E *  const_iterator;
    typedef _E &        reference;
    typedef const _E &  const_reference;
  
  protected:
    // указатели на голову и хвост
    size_type _L_len;
    iterator __Head;
    iterator __Tail;
  
  public:
    // конструктор по умолчанию
    Base() : _L_len(0U), __Head(nullptr), __Tail(nullptr) { }
    Base(size_type size, iterator It_start = nullptr, iterator It_end = nullptr)
      : _L_len(size), __Head(It_start), __Tail(It_end) {}
    // destruct
    ~Base() {
      __Head = nullptr;
      __Tail = nullptr;
      _L_len = 0U;
    }

    iterator begin() noexcept { return __Head; }
    const_iterator cbegin() noexcept { return __Head; }
    iterator end() noexcept { return __Tail; }
    const_iterator cend() noexcept { return __Tail; }
    reference &front() { return *begin(); }
    reference &back() { return *end(); }
    constexpr size_type size() const noexcept { return _M_len; }
    bool empty() { return __Head == nullptr; }

};

}

#endif