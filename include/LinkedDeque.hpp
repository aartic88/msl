#ifndef LINKEDDEQUE_HPP_
#define LINKEDDEQUE_HPP_
#include "doublylinklist.hpp"

class LinkedDeque {
public:
  LinkedDeque();
  int size() const;
  bool empty() const;
  std::string &front() const;
  std::string &back() const;
  void insertfront(const std::string &);
  void insertback(const std::string &);
  void removefront();
  void removeback();
  void print();

private:
  DoublyLinkedList dque;
  int sz;
};
LinkedDeque::LinkedDeque() : dque() {}
int LinkedDeque::size() const { return sz; }
bool LinkedDeque::empty() const { return sz == 0; }
std::string &LinkedDeque::front() const { return dque.front(); }
std::string &LinkedDeque::back() const { return dque.back(); }
void LinkedDeque::insertfront(const std::string &data) {
  dque.addfront(data);
  sz++;
}
void LinkedDeque::insertback(const std::string &data) {
  dque.addback(data);
  sz++;
}
void LinkedDeque::removefront() {
  if (empty()) {
    dque.removefront();
    sz--;
  } else {
    throw "Empty Deque";
  }
}
void LinkedDeque::removeback() {
  if (empty()) {
    dque.removeback();
    sz--;
  } else {
    throw "Empty Deque";
  }
}
void LinkedDeque::print() { dque.printlist(); }
#endif