#include <cmath>
#include <gtest/gtest.h>
#include <string>
#include <vector>
using namespace std;
class Doublelinklist {
public:
  Doublelinklist(string value, Doublelinklist *prev, Doublelinklist *next)
      : value(value), prev(prev), next(next) {}
  friend Doublelinklist *createList(const string &name);
  friend ostream &operator<<(ostream &out, Doublelinklist &link);
  friend ostream &operator<<(ostream &out, Doublelinklist *link);
  friend void add(Doublelinklist *current, Doublelinklist *newNode);
  friend string &getValue(Doublelinklist *node);

private:
  string value;
  Doublelinklist *next, *prev;
};

Doublelinklist *createList(const string &name) {
  Doublelinklist *link = new Doublelinklist{name, nullptr, nullptr};
  return link;
}

ostream &operator<<(ostream &out, Doublelinklist &link) {
  out << "{" << link.value << ", " << (void *)link.prev << ", "
      << (void *)link.next << "}";
  return out;
}
ostream &operator<<(ostream &out, Doublelinklist *link) {
  out << "[";
  while (link != nullptr) {
    out << (void *)link << " = " << *link << ", ";
    link = link->next;
  }
  out << "]";
  return out;
}

void add(Doublelinklist *current, Doublelinklist *newNode) {
  if (current->prev == nullptr) {
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
  } else {
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
  }
}

string &getValue(Doublelinklist *node) {
  if (node != nullptr) {
    return node->value;
  }
  throw "bad input";
}
TEST(testIsLinkedList, basicTest) {
  Doublelinklist *root = createList("Aarti");
  std::cout << root << endl;

  Doublelinklist *node = createList("Deepak");
  add(root, node);
  std::cout << root << endl;

  node = createList("Aarya");
  add(root, node);
  std::cout << root<< endl;
}