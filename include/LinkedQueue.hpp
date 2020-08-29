#ifndef LINKEDQUEUE_HPP_
#define LINKEDQUEUE_HPP_
#include "CircularlyLinkedList.hpp"
#include <string>
template <typename E> class LinkedQueue {
public:
  LinkedQueue();
  int size() const;
  bool empty() const;
  E &front() const;        // return front value
  void enqueue(const E &); // add value
  void dequeue();          // remove value
  void print();

private:
  CircularlyLinkedList<E> que;
  int n;
};
template <typename E> LinkedQueue<E>::LinkedQueue() : que(), n(0) {}
template <typename E> int LinkedQueue<E>::size() const { return n; }
template <typename E> bool LinkedQueue<E>::empty() const { return n == 0; }
template <typename E> E &LinkedQueue<E>::front() const {
  if (!empty()) {
    return que.front();
  } else {
    throw "Empty queue";
  }
}
template <typename E> void LinkedQueue<E>::enqueue(const E &data) {
  que.add(data);
  que.advance();
  n++;
}
template <typename E> void LinkedQueue<E>::dequeue() {
  if (!empty()) {
    que.remove();
  } else {
    throw "Empty queue";
  }
  n--;
}
template <typename E> void LinkedQueue<E>::print() { que.printlist(); }
#endif