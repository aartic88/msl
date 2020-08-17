#ifndef LISTPRIORITYQUEUE_HPP_
#define LISTPRIORITYQUEUE_HPP_

#include <cmath>
#include <iostream>
#include <list>

template <typename E> class isLess {
public:
  bool operator()(const E &e, const E &p) const { return e < p; }
};

class isLessInt {
public:
  bool operator()(const int &e, const int &p) const { return e < p; }
};

template <typename E, typename C = isLess<E>> class ListPriorityQueue {
public:
  int size() const;
  bool empty() const;
  void insert(const E &e);
  const E &min() const;
  void removeMin();

private:
  std::list<E> L;
  C isLess;
};

template <typename E, typename C> int ListPriorityQueue<E, C>::size() const {
  return L.size();
}
template <typename E, typename C> bool ListPriorityQueue<E, C>::empty() const {
  return L.empty();
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::insert(const E &e) {
  typename std::list<E>::iterator p;
  p = L.begin();
  while (p != L.end() && !isLess(e, *p))
    ++p;
  L.insert(p, e);
}
template <typename E, typename C>
const E &ListPriorityQueue<E, C>::min() const {
  return L.front();
}
template <typename E, typename C> void ListPriorityQueue<E, C>::removeMin() {
  L.pop_front();
}

#endif