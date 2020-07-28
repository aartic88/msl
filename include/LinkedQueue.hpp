#ifndef LINKEDQUEUE_HPP_
#define LINKEDQUEUE_HPP_
#include<string>
#include "CircularlyLinkedList.hpp"


class LinkedQueue {
public:
  LinkedQueue();
  bool empty() const;
  std::string &front() const;
  void enqueue(const std::string &);
  void dequeue();
  void print();

private:
  CircularlyLinkedList que;
};
LinkedQueue::LinkedQueue() : que() {}
bool LinkedQueue::empty() const { return que.size(); }

std::string &LinkedQueue::front() const {
  if (empty()) {
    return que.front();
  } else {
    throw "Empty queue";
  }
}

void LinkedQueue::enqueue(const std::string &data) {
  que.add(data);
  que.advance();
}
void LinkedQueue::dequeue() {
  if (empty()) {
    que.remove();
  } else {
    throw "Empty queue";
  }
}
void LinkedQueue::print() { que.printlist(); }
#endif