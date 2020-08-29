#ifndef SINGLYLINKEDLIST_HPP_
#define SINGLYLINKEDLIST_HPP_
#include <iostream>
#include <string>
// using namespace std;
template <typename E> class SNode {
private:
  E data;
  SNode<E> *next;
  template <typename L> friend class SinglyLinkedList;   //friend class SinglyLinkedList<E> wasnt accepting????????? 
};

template <typename E> class SinglyLinkedList {
public:
  SinglyLinkedList();
 ~SinglyLinkedList();
  bool empty() const;
  E &front() const;
  SNode<E> *addfront(const E &d);
  void removefront();
  void printlist();
   E &getValue(SNode<E> *);
   SNode<E> *getNextAddress(SNode<E> *);
  int size() const { return sz; };

private:
  SNode<E> *head;
  int sz = 0;
};
template <typename E> SinglyLinkedList<E>::SinglyLinkedList() : head(NULL) {}

template <typename E>SinglyLinkedList<E> ::~SinglyLinkedList() {
  while (!empty())
    removefront();
}

template <typename E> bool SinglyLinkedList<E>::empty() const {
  return head == NULL;
}

template <typename E> E &SinglyLinkedList<E>::front() const {
  return head->data;
}

template <typename E> SNode<E> *SinglyLinkedList<E>::addfront(const E &d) {
  SNode<E> *temp = new SNode<E>;
  temp->data = d;
  temp->next = head;
  head = temp;
  sz++;
  return head;
}

template <typename E>
void SinglyLinkedList<E>::removefront() {
  SNode<E> *old = head;
  head = old->next;
  sz--;
  delete old;
}

template <typename E>
void SinglyLinkedList<E>::printlist() {
  SNode<E> *temp = head;
  std::cout << "{";
  while (temp) {
    std::cout << temp->data;
    temp = temp->next;
    std::cout << " ";
  }
  std::cout << "} Size = " << size();
}
template <typename E>
E &SinglyLinkedList<E>::getValue(SNode<E> *temp) {
  if (temp != nullptr) {
    return temp->data;
  }
  throw "bad input";
}

template <typename E>
SNode<E> *SinglyLinkedList<E>::getNextAddress(SNode<E> *temp) {
  if (temp != nullptr) {
    return temp->next;
  }
  return nullptr;
}
#endif