#ifndef S21_CONTAINERS_TESTS_H
#define S21_CONTAINERS_TESTS_H


#include <gtest/gtest.h>
#include <cstdlib>
#include <cstring>

#include "../s21_containers.h"

#include <iostream>

template <class T2>
class Pifpaf {
  public:
    using value_type = T2;
    using reference = T2 &;
    using iterator = T2 *;
    using size_type = size_t;

    iterator arr;
    size_type size_arr;

    // construct without parameters
    Pifpaf() {
      arr = nullptr;
      size_arr = 0;
    }
    // construct one parameter
    Pifpaf(size_type size) {
      size_arr = size;
      arr = new value_type[size];
    }
    // construct copy
    Pifpaf(const Pifpaf& other) {
      size_arr = other.size_arr;
      arr = new value_type[size_arr];
      for (size_t i = 0; i < size_arr; ++i) {
        arr[i] = other.arr[i];
      }
    }
    // construct with 2 parameters
    Pifpaf(size_type size, value_type value) {
      size_arr = size;
      arr = new value_type[size]{value};
    }

    // construct with initializer list
    Pifpaf(std::initializer_list<T2> &items) : Pifpaf(items.size()) {
      size_t i = 0;
      for (auto it = items.begin(); it != items.end(); ++it) {
        arr[i] = *it;
        ++i;
      }
    }
    // destruct
    ~Pifpaf() {
      if (arr != nullptr) {
        delete[] arr;
      }
    }
    // compair obj
    bool operator!=(Pifpaf& other) {
      return (arr != other.arr);
    }
    // check obj
    bool isEmpty() {
      return arr == nullptr;
    }
    // iterators
    iterator operator++() {
      return ++arr;
    }
    iterator operator--() {
      return --arr;
    }
    iterator begin() { return &arr[0]; };
    iterator end() { return &arr[0] + size_arr; };
};

#endif  // S21_CONTAINERS_TESTS_H
