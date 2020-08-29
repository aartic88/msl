#ifndef CIRCULARYLINKEDLIST_HPP_
#define CIRCULARYLINKEDLIST_HPP_

#include <iostream>
#include <string>
template <typename E> class CNode {
private:
  E data;
  CNode<E> *next;
  template <typename L> friend class CircularlyLinkedList;
};
template <typename E> class CircularlyLinkedList {
public:
  CircularlyLinkedList();
  ~CircularlyLinkedList();
  bool empty() const;
  E &front() const;
  E &back() const;
  void add(const E &d);
  void advance();
  void remove();
  void printlist();
  int size() const { return sz; }

private:
  CNode<E> *cursor;
  int sz = 0;
};
template <typename E>
CircularlyLinkedList<E>::CircularlyLinkedList() : cursor(NULL) {}
template <typename E> CircularlyLinkedList<E>::~CircularlyLinkedList() {
  while (!empty())
    remove();
}
template <typename E> bool CircularlyLinkedList<E>::empty() const {
  return cursor == NULL;
}
template <typename E>
void CircularlyLinkedList<E>::remove() { // remove node after cursor
  CNode<E> *old = cursor->next;
  if (old == cursor) { // only node
    cursor = NULL;
  } else {
    cursor->next = old->next;
  }
  sz--;
  delete old;
}
template <typename E> E &CircularlyLinkedList<E>::front() const {
  return cursor->next->data;
}
template <typename E> E &CircularlyLinkedList<E>::back() const {
  return cursor->data;
}
template <typename E>
void CircularlyLinkedList<E>::add(const E &data) { // after cursor
  CNode<E> *temp = new CNode<E>;
  temp->data = data;
  if (cursor == NULL) {
    temp->next = temp; // single node
    cursor = temp;
    sz++;
  } else {
    temp->next = cursor->next;
    cursor->next = temp;
    sz++;
  }
}
template <typename E> void CircularlyLinkedList<E>::advance() {
  cursor = cursor->next;
}
template <typename E> void CircularlyLinkedList<E>::printlist() {
  CNode<E> *temp = cursor;
  std::cout << "{";
  for (int i = 0; i < size(); i++) {
    std::cout << temp->data;
    temp = temp->next;
    std::cout << " ";
  }
  std::cout << "} Size = " << size();
}

#endif // CIRCULARLYLINKEDLIST_HPP_