#ifndef ARRAYQUEUE_HPP_
#define ARRAYQUEUE_HPP_

#include <iostream>
#include <string>
// destructor,copy constructor,assignment oprator ommited.
class ArrayQueue {
  enum { DEF_CAPACITY = 100 };

public:
  ArrayQueue(int cap = DEF_CAPACITY);
  bool empty() const;
  int size() const;
  int front() const;
  void enqueue(const int &d);
  void dequeue();
  void print();

private:
  int *data;
  int capacity;
  int frontIndex = 0, rearIndex = 0, sz = 0;
};

ArrayQueue::ArrayQueue(int cap)
    : data(new int[cap]), capacity(cap), frontIndex(0), rearIndex(0), sz(0) {}

bool ArrayQueue::empty() const { return sz == 0; }

int ArrayQueue::size() const { return sz; }

int ArrayQueue::front() const {
  if (!empty()) {
    return data[frontIndex];
  } else {
    throw "empty stack";
  }
}
void ArrayQueue::enqueue(const int &d) {
  if (size() == capacity) {
    throw "Stack is Full";
  } else {
    data[rearIndex] = d;
    rearIndex = (rearIndex + 1) % capacity;
    sz++;
  }
}
void ArrayQueue::dequeue() {
  if (!empty()) {
    frontIndex = (frontIndex + 1) % capacity;
    sz--;
  } else {
    throw "empty Stack";
  }
}
void ArrayQueue::print() {
  for (int i = frontIndex; i < rearIndex; i++) {
    std::cout << data[i] << " ";
  }
}
#endif