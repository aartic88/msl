
#include <iostream>
#include <string>
// using namespace std;
class Node {
  friend class Singlylinklist;

private:
  std::string data;
  Node *next;
};
class Singlylinklist {
public:
  Singlylinklist();
  ~Singlylinklist();
  bool empty() const;
  std::string front();
  Node *addfront(const std::string &d);
  void removefront();
  void printlist();
  std::string &getValue(Node *);
  Node *getNextAddress(Node *);

private:
  Node *head;
};
Singlylinklist::Singlylinklist() : head(NULL) {}
Singlylinklist::~Singlylinklist() {
  while (!empty())
    removefront();
}
bool Singlylinklist::empty() const { return head == NULL; }
std::string Singlylinklist::front() { return head->data; }
Node *Singlylinklist::addfront(const std::string &d) {
  Node *temp = new Node;
  temp->data = d;
  temp->next = head;
  head = temp;
  return head;
}
void Singlylinklist::removefront() {
  Node *old = head;
  head = old->next;
  delete old;
}
void Singlylinklist::printlist() {
  Node *temp = head;
  std::cout << "{";
  while (temp) {
    std::cout << temp->data;
    temp = temp->next;
    std::cout << " ";
  }
  std::cout << "}";
}
std::string &Singlylinklist::getValue(Node *temp) {
  if (temp != nullptr) {
    return temp->data;
  }
  throw "bad input";
}
Node *Singlylinklist::getNextAddress(Node *temp) {
  if (temp != nullptr) {
    return temp->next;
  }
  return nullptr;
}