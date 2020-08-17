#ifndef NODELIST_HPP_
#define NODELIST_HPP_

#include <iostream>
#include <string>

class NodeList {
private:
  // ------NODE CLASS------
  struct Node {
    int data;
    Node *prev;
    Node *next;
  };

public:
  // ------ITERATOR CLASS--------
  class Iterator {
  public:
    int &operator*();
    bool operator==(const Iterator &p) const;
    bool operator!=(const Iterator &p) const;
    Iterator &operator++();
    Iterator &operator--();
    friend class NodeList; // so constructor is accecible in node class

  private:
    Node *v;
    Iterator(Node *u); //??????Why is constructor Private???????
  };
  // ------NODELIST Methods------
  NodeList();
  int size() const;
  bool empty() const;
  Iterator begin() const;
  Iterator end() const;
  void insertFront(const int &);
  void insertBack(const int &);
  void insert(const Iterator &, const int &);
  void eraseFront();
  void eraseBack();
  void erase(const Iterator &);

private:
  // -----NODELIST variables----
  int n;
  Node *header, *trailer;
};

//---------Definitions of ITERATOR CLASS-------
NodeList::Iterator::Iterator(Node *u) { v = u; }
int &NodeList::Iterator::operator*() { return v->data; }
bool NodeList::Iterator::operator==(const Iterator &p) const {
  return v == p.v;
}
bool NodeList::Iterator::operator!=(const Iterator &p) const {
  return v != p.v;
}
NodeList::Iterator &NodeList::Iterator::operator++() {
  v = v->next;
  return *this;
}
NodeList::Iterator &NodeList::Iterator::operator--() {
  v = v->prev;
  return *this;
}
//----------Definitions of NODELIST CLASS---------
NodeList::NodeList() {
  n = 0;
  header = new Node;
  trailer = new Node;
  header->next = trailer;
  trailer->prev = header;
}
int NodeList::size() const { return n; }
bool NodeList::empty() const { return n == 0; }
NodeList::Iterator NodeList::begin() const { return Iterator(header->next); }
NodeList::Iterator NodeList::end() const { return Iterator(trailer); }
void NodeList::insert(const NodeList::Iterator &p, const int &e) {
  Node *w = p.v;
  Node *u = w->prev;
  Node *v = new Node;
  v->data = e;
  v->next = w;
  w->prev = v;
  v->prev = u;
  u->next = v;
  n++;
}
void NodeList::insertFront(const int &e) { insert(begin(), e); }
void NodeList::insertBack(const int &e) { insert(end(), e); }
void NodeList::erase(const Iterator &p) {
  Node *v = p.v;
  Node *w = v->next;
  Node *u = v->prev;
  u->next = w;
  w->prev = u;
  delete v;
  n--;
}
void NodeList::eraseFront() { erase(begin()); }
void NodeList::eraseBack() { erase(--end()); }

#endif