#ifndef BASE_VECTOR_ITERATOR
#define BASE_VECTOR_ITERATOR

namespace s21 {
template <typename __E>
class Base {
	public:
	typedef __E value_type;
	typedef __E *iterator;
	typedef __E *reverse_iterator;
	typedef const __E *const_iterator;
	typedef const __E *const_reverse_iterator;
	typedef __E &reference;
	typedef const __E &const_reference;
	typedef size_t size_type;
	
	protected:
	size_type _M_len;
	void set_ptr(iterator data) { __Ptr = data; }
	
	private:
	iterator __Ptr;

	public:
	Base() : _M_len(0U), __Ptr(nullptr) {}
	Base(size_type n, iterator ptr) : _M_len(n), __Ptr(ptr) {}
	// Base(value_type &other) : _M_len(other._M_len) {}

	~Base() { // destructor
		_M_len = 0U;
		__Ptr = nullptr;
	}
	
	// iterator metods
	iterator begin() noexcept { return __Ptr; }
	const_iterator cbegin() const noexcept { return __Ptr; }
	iterator end() noexcept { return __Ptr + _M_len; }
	const_iterator cend() const noexcept { return __Ptr + _M_len; }
	reverse_iterator rbegin() noexcept { return __Ptr + _M_len - 1; }
	const_reverse_iterator crbegin() const noexcept { return __Ptr + _M_len - 1; }
	reverse_iterator rend() noexcept { return __Ptr; }
	const_reverse_iterator crend() const noexcept { return __Ptr; }
	value_type &front() { return *(this->begin()); }
	value_type &back() { return *(this->end() - 1); }
	constexpr size_type size() const noexcept { return _M_len; }
	bool empty() { return begin() == end(); }
};

// iterators
template <class _Tp>
constexpr const _Tp *begin(Base<_Tp> __ils) noexcept {
  return __ils.begin();
}
template <class _Tp>
constexpr const _Tp *end(Base<_Tp> __ils) noexcept {
  return __ils.end();
}

} // namespace s21

// #include "base_sequence_cont.cpp"

#endif