#ifndef DOUBLYLINKEDLIST_HPP_
#define DOUBLYLINKEDLIST_HPP_

#include <string>
#include <iostream>
class Node
{
  friend class DoublyLinkList;

private:
  std::string data;
  Node *prev;
  Node *next;
};
class DoublyLinkList
{
public:
  DoublyLinkList();
  ~DoublyLinkList();
  bool empty();

  void remove(Node *);
  void removefront();
  void removeback();

  void add(Node *, const std::string &);
  void addfront(const std::string &);
  void addback(const std::string &);

  void printlist();

private:
  Node *header;
  Node *trailer;
};
DoublyLinkList::DoublyLinkList()
{
  header = new Node;
  trailer = new Node;
  header->next = trailer;
  trailer->prev = header;
}
DoublyLinkList::~DoublyLinkList()
{
  while (!empty())
    removefront();
  delete header;
  delete trailer;
}
bool DoublyLinkList::empty() { return (header->next == trailer); }
void DoublyLinkList::remove(Node *v)
{
  Node *u = v->prev;
  Node *w = v->next;
  u->next = w;
  w->prev = u;
  delete v;
}
void DoublyLinkList::removefront() { remove(header->next); }
void DoublyLinkList::removeback() { remove(trailer->prev); }

void DoublyLinkList::add(Node *v, const std::string &d)
{
  Node *temp = new Node;
  temp->data = d;
  temp->next = v;
  temp->prev = v->prev;
  v->prev->next = temp;
  v->prev = temp;
}
void DoublyLinkList::addfront(const std::string &d)
{
  add(header->next, d);
}
void DoublyLinkList::addback(const std::string &d)
{
  add(trailer->prev, d);
}
void DoublyLinkList::printlist()
{
  Node *temp = header->next;
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