#ifndef DOUBLYLINKEDLIST_HPP_
#define DOUBLYLINKEDLIST_HPP_

#include <string>
#include <iostream>
template <typename E>class DNode
{
  template <typename L> friend class DoublyLinkedList;

private:
  E data;
  DNode<E> *prev;
  DNode<E> *next;
};
template <typename E> class DoublyLinkedList
{
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  bool empty();

  E &front()const;
  E &back()const;

  void remove(DNode<E> *);
  void removefront();
  void removeback();

  void add(DNode<E> *, const E &);
  void addfront(const E &);
  void addback(const E &);

  void printlist();

private:
  DNode<E> *header;
  DNode<E> *trailer;
};
template <typename E> 
DoublyLinkedList<E>::DoublyLinkedList()
{
  header = new DNode<E>;
  trailer = new DNode<E>;
  header->next = trailer;
  trailer->prev = header;
}
template <typename E> 
DoublyLinkedList<E>::~DoublyLinkedList()
{
  while (!empty())
    removefront();
  delete header;
  delete trailer;
}
template <typename E> 
bool DoublyLinkedList<E>::empty() { return (header->next == trailer); }
template <typename E> 
E &DoublyLinkedList<E>::front()const{
  return header->next->data;
}
template <typename E> 
E &DoublyLinkedList<E>::back()const{
  return trailer->prev->data;
}
template <typename E> 
void DoublyLinkedList<E>::remove(DNode<E> *v)
{
  DNode<E> *u = v->prev;
  DNode<E> *w = v->next;
  u->next = w;
  w->prev = u;
  delete v;
}
template <typename E> 
void DoublyLinkedList<E>::removefront() { remove(header->next); } //NOLINT
template <typename E> 
void DoublyLinkedList<E>::removeback() { remove(trailer->prev); }
template <typename E> 
void DoublyLinkedList<E>::add(DNode<E> *v, const E &d)
{
  DNode<E> *temp = new DNode<E>;
  temp->data = d;
  temp->next = v;
  temp->prev = v->prev;
  v->prev->next = temp;
  v->prev = temp;
}
template <typename E> 
void DoublyLinkedList<E>::addfront(const E &d)
{
  add(header->next, d);
}
template <typename E> 
void DoublyLinkedList<E>::addback(const E &d)
{
  add(trailer->prev, d);
}
template <typename E> 
void DoublyLinkedList<E>::printlist()
{
  DNode<E> *temp = header->next;
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