#ifndef LINKEDSTACK_HPP_
#define LINKEDSTACK_HPP_
#include "SinglyLinkedList.hpp"

template <typename E>
class LinkedStack {
public:
  LinkedStack();
  bool empty() const;
  const E& top() const;
  void push(const E &);
  void pop();
  void print();

private:
  SinglyLinkedList<E> stk;
};
template <typename E>
LinkedStack<E>::LinkedStack() : stk() {}

template <typename E>
bool LinkedStack<E>::empty() const { return stk.size(); }

template <typename E>
const E& LinkedStack<E>::top() const {
  if (empty() != 0) {
    return stk.front();
  } else {
    throw "Empty stack";
  }
}

template <typename E>
void LinkedStack<E>::push(const E &data) { stk.addfront(data); }

template <typename E>
void LinkedStack<E>::pop() {
  if (empty() != 0) {
    stk.removefront();
  } else {
    throw "Empty stack";
  }
}

template <typename E>
void LinkedStack<E>::print() { stk.printlist(); }
#endif