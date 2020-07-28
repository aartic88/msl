#ifndef CIRCULARYLINKEDLIST_HPP_
#define CIRCULARYLINKEDLIST_HPP_

#include <iostream>
#include <string>

class CNode {
private:
  std::string data;
  CNode *next;
  friend class CircularlyLinkedList;
};

class CircularlyLinkedList {
public:
  CircularlyLinkedList();
  ~CircularlyLinkedList();
  bool empty() const;
  std::string &front() const;
  std::string &back() const;
  void add(const std::string &d);
  void advance();
  void remove();
  void printlist();
  int size() const { return sz; }

private:
  CNode *cursor;
  int sz = 0;
};

CircularlyLinkedList::CircularlyLinkedList() : cursor(NULL) {}
CircularlyLinkedList::~CircularlyLinkedList() {
  while (!empty())
    remove();
}

bool CircularlyLinkedList::empty() const { return cursor == NULL; }

void CircularlyLinkedList::remove() { // remove node after cursor
  CNode *old = cursor->next;
  if (old == cursor) { // only node
    cursor = NULL;
  } else {
    cursor->next = old->next;
  }
  sz--;
  delete old;
}

std::string &CircularlyLinkedList::front() const { return cursor->next->data; }

std::string &CircularlyLinkedList::back() const { return cursor->data; }

void CircularlyLinkedList::add(const std::string &data) { // after cursor
  CNode *temp = new CNode;
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
void CircularlyLinkedList::advance() { cursor = cursor->next; }

void CircularlyLinkedList::printlist() {
  CNode *temp = cursor;
  std::cout << "{";
  for (int i = 0; i < size(); i++) {
    std::cout << temp->data;
    temp = temp->next;
    std::cout << " ";
  }
  std::cout << "} Size = " << size();
}

#endif // CIRCULARLYLINKEDLIST_HPP_