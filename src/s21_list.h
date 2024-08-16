#ifndef S21_LIST_H
#define S21_LIST_H

#include <exception>
#include <initializer_list>

template <class T>
class List {
 private:
  struct Node {
    T data;
    Node *next;
    Node *prev;
  };
  Node *head;
  Node *tail;
  size_t size;

 public:
  List() : head(nullptr), tail(nullptr), size(0){};
  List(std::initializer_list<T> list) : List() {
    for (auto it = list.begin(); it != list.end(); ++it) {
      push_back(*it);
    }
  };

  // Node front();
  // Node back();
  // void push_front(value_type data);
  // void push_back(value_type data);
  // void pop_front();
  // void pop_back();

  // remove(reference )
};

#endif
