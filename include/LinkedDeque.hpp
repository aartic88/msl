#ifndef LINKEDDEQUE_HPP_
#define LINKEDDEQUE_HPP_
#include "doublylinklist.hpp"
template <typename E> class LinkedDeque {
public:
  LinkedDeque();
  int size() const;
  bool empty() const;
  E &front() const;
  E &back() const;
  void insertfront(const E &);
  void insertback(const E &);
  void removefront();
  void removeback();
  void print();

private:
  DoublyLinkedList<E> dque;
  int sz;
};

template <typename E> LinkedDeque<E>::LinkedDeque() : dque() {}

template <typename E> int LinkedDeque<E>::size() const { return sz; }

template <typename E> bool LinkedDeque<E>::empty() const { return sz == 0; }

template <typename E> E &LinkedDeque<E>::front() const { return dque.front(); }

template <typename E> E &LinkedDeque<E>::back() const { return dque.back(); }

template <typename E> void LinkedDeque<E>::insertfront(const E &data) {
  dque.addfront(data);
  sz++;
}

template <typename E> void LinkedDeque<E>::insertback(const E &data) {
  dque.addback(data);
  sz++;
}

template <typename E> void LinkedDeque<E>::removefront() {
  if (!empty()) {
    dque.removefront();
    sz--;
  } else {
    throw "Empty Deque";
  }
}

template <typename E> void LinkedDeque<E>::removeback() {
  if (!empty()) {
    dque.removeback();
    sz--;
  } else {
    throw "Empty Deque";
  }
}

template <typename E> void LinkedDeque<E>::print() { dque.printlist(); }
#endif