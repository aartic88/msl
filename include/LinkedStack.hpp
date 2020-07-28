#ifndef LINKEDSTACK_HPP_
#define LINKEDSTACK_HPP_
#include "SinglyLinkedList.hpp"
class LinkedStack {
public:
  LinkedStack();
  bool empty() const;
  std::string &top() const;
  void push(const std::string &);
  void pop();
  void print();

private:
  SinglyLinkedList stk;
};
LinkedStack::LinkedStack() : stk() {}
bool LinkedStack::empty() const { return stk.size(); }
std::string &LinkedStack::top() const {
  if (empty() != 0) {
    return stk.front();
  } else {
    throw "Empty stack";
  }
}
void LinkedStack::push(const std::string &data) { stk.addfront(data); }
void LinkedStack::pop() {
  if (empty() != 0) {
    stk.removefront();
  } else {
    throw "Empty stack";
  }
}
void LinkedStack::print() { stk.printlist(); }
#endif