#ifndef ARRAYSTACK_HPP_
#define ARRAYSTACK_HPP_

#include <iostream>
#include <string>
// destructor,copy constructor,assignment oprator ommited.
class ArrayStack {
  enum { DEF_CAPACITY = 100 };

public:
  ArrayStack(int cap = DEF_CAPACITY);
  bool empty() const;
  int size() const;
  int top() const;
  void push(const int &d);
  void pop();
  void print();

private:
  int *data;
  int capacity;
  int index;
};
ArrayStack::ArrayStack(int cap)
    : data(new int[cap]), capacity(cap), index(-1) {}

bool ArrayStack::empty() const { return index < 0; }

int ArrayStack::size() const { return index + 1; }
int ArrayStack::top() const {
  if (!empty()) {
    return data[index];
  } else {
    throw "empty stack";
  }
}
void ArrayStack::push(const int &d) {
  if (size() == capacity) {
    throw "Stack is Full";
  } else {
    data[++index] = d;
  }
}
void ArrayStack::pop() {
  if (!empty()) {
    index--;
  } else {
    throw "empty Stack";
  }
}
void ArrayStack::print() {
  for (int i = 0; i < size(); i++) {
    std::cout << data[i] << " ";
  }
}
#endif