#ifndef SINGLYLINKEDLIST_HPP_
#define SINGLYLINKEDLIST_HPP_
#include <iostream>
#include <string>
// using namespace std;
class Node {
  friend class SinglyLinkedList;

private:
  std::string data;
  Node *next;
};
class SinglyLinkedList {
public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  bool empty() const;
  std::string &front()const;
  Node *addfront(const std::string &d);
  void removefront();
  void printlist();
  std::string &getValue(Node *);
  Node *getNextAddress(Node *);
  int size()const { return sz; };

private:
  Node *head;
  int sz = 0;
};
SinglyLinkedList::SinglyLinkedList() : head(NULL) {}
SinglyLinkedList::~SinglyLinkedList() {
  while (!empty())
    removefront();
}
bool SinglyLinkedList::empty() const { return head == NULL; }
std::string &SinglyLinkedList::front()const { return head->data; }
Node *SinglyLinkedList::addfront(const std::string &d) {
  Node *temp = new Node;
  temp->data = d;
  temp->next = head;
  head = temp;
  sz++;
  return head;
}
void SinglyLinkedList::removefront() {
  Node *old = head;
  head = old->next;
  sz--;
  delete old;
}
void SinglyLinkedList::printlist() {
  Node *temp = head;
  std::cout << "{";
  while (temp) {
    std::cout << temp->data;
    temp = temp->next;
    std::cout << " ";
  }
  std::cout << "} Size = " << size();
}
std::string &SinglyLinkedList::getValue(Node *temp) {
  if (temp != nullptr) {
    return temp->data;
  }
  throw "bad input";
}
Node *SinglyLinkedList::getNextAddress(Node *temp) {
  if (temp != nullptr) {
    return temp->next;
  }
  return nullptr;
}
#endif