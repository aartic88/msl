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
  friend ostream & operator<< (ostream & out, Doublelinklist & link);
  friend string &getValue(Doublelinklist *node);

private:
  string value;
  Doublelinklist *next, *prev;
};

Doublelinklist *createList(const string &name) {
  Doublelinklist *link = new Doublelinklist{name, nullptr, nullptr};
  return link;
}

ostream & operator<< (ostream & out, Doublelinklist & link) {
    out << "{"<< link.value << ", " <<(void *)link.prev << ", " <<(void *)link.next << "}";
    return out;
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
}