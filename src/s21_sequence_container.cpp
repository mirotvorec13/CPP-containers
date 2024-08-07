#include "s21_sequence_container.h"

using namespace s21;

template <class value_type>
s21::SequenceContainer<value_type>&
s21::SequenceContainer<value_type>::operator=(
    s21::SequenceContainer<value_type>& other) {
  if (this != &other) {
    SequenceContainer<value_type> data;
    data._M_array = other._M_array;
    data._M_len = other.size();
    return *data;
  }
}
// default construct
// template <typename T>
// sequence_container<T>::sequence_container(){

// }

// template <typename T>
// sequence_container<T>& sequence_container<T>::operator=(const
// sequence_container<T> &other) {
//     if (std::__type_identity(this) != std::__type_identity(other)) {
//         throw std::__failure_type(&other);
//     }
//     if (this != &other) {
//         this = other;
//     }

//     return *this;
// }

// template <typename T>
// void sequence_container<T>::push_back(T &v) {
//     if (m_size == m_capacity)
//     {
//         reserve_more_capacity(m_size * 2);
//     }
//     arr[m_size++] = v;
// }