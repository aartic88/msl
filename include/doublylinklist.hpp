#ifndef DOUBLYLINKEDLIST_HPP_
#define DOUBLYLINKEDLIST_HPP_

#include <string>
#include <iostream>
class DNode
{
  friend class DoublyLinkedList;

private:
  std::string data;
  DNode *prev;
  DNode *next;
};
class DoublyLinkedList
{
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  bool empty();

  std::string &front()const;
  std::string &back()const;

  void remove(DNode *);
  void removefront();
  void removeback();

  void add(DNode *, const std::string &);
  void addfront(const std::string &);
  void addback(const std::string &);

  void printlist();

private:
  DNode *header;
  DNode *trailer;
};
DoublyLinkedList::DoublyLinkedList()
{
  header = new DNode;
  trailer = new DNode;
  header->next = trailer;
  trailer->prev = header;
}
DoublyLinkedList::~DoublyLinkedList()
{
  while (!empty())
    removefront();
  delete header;
  delete trailer;
}
bool DoublyLinkedList::empty() { return (header->next == trailer); }

std::string &DoublyLinkedList::front()const{
  return header->next->data;
}

std::string &DoublyLinkedList::back()const{
  return trailer->prev->data;
}

void DoublyLinkedList::remove(DNode *v)
{
  DNode *u = v->prev;
  DNode *w = v->next;
  u->next = w;
  w->prev = u;
  delete v;
}
void DoublyLinkedList::removefront() { remove(header->next); } //NOLINT
void DoublyLinkedList::removeback() { remove(trailer->prev); }

void DoublyLinkedList::add(DNode *v, const std::string &d)
{
  DNode *temp = new DNode;
  temp->data = d;
  temp->next = v;
  temp->prev = v->prev;
  v->prev->next = temp;
  v->prev = temp;
}
void DoublyLinkedList::addfront(const std::string &d)
{
  add(header->next, d);
}
void DoublyLinkedList::addback(const std::string &d)
{
  add(trailer->prev, d);
}
void DoublyLinkedList::printlist()
{
  DNode *temp = header->next;
  std::cout << "{";
  while (temp != trailer)
  {
    std::cout << temp->data;
    temp = temp->next;
    std::cout << " ";
  }
  std::cout << "}";
}
#endif //DOUBLYLINKEDLIST_HPP_