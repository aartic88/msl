#include <gtest/gtest.h>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Link {
    friend ostream & operator<< (ostream & out, Link & link);
    friend string & getValue(Link * node);
    friend Link * getNextAddress(Link * node);
    friend Link * createList (const string & name);
    friend void add (Link * current, Link * newNode);
    friend ostream & operator<< (ostream & out, Link * link) ;
    std::string value;
    Link * next;
public:
    Link(std::string value, Link * next):value(value), next(next) {

    }

};

string & getValue(Link * node) {
    if (node != nullptr) {
        return node->value;
    }
    throw "bad input";
}

Link * getNextAddress(Link * node) {
    if (node != nullptr) {
        return node->next;
    }
    return nullptr;
}

Link * createList (const string & name) {
    Link * link = new Link {name, nullptr};
    return link;
}

/**
 *  [n1] -> [n2] -> [n3] -> [current] -> [n4] -> [n5] -> [null]
 *  after the operation
 *  [n1] -> [n2] -> [n3] -> [current] ->[newNode] ->[n4] -> [n5] -> [null]
*/
void add (Link * current, Link * newNode) {
    Link * current_next = current->next;
    current->next = newNode;
    newNode->next = current_next;
}


ostream & operator<< (ostream & out, Link & link) {
    out << "{"<< link.value << ", " <<(void *)link.next << "}";
    return out;
}

ostream & operator<< (ostream & out, Link * link) {
    out << "[";
    while (link != nullptr) {
         out <<(void *)link << " = " << *link << ", ";
         link = link->next;
    }
    out << "]";
    return out;
}

TEST(testIsLinkedList, basicTest)
{
  Link * root = createList("Aarti");
  std::cout << root<< endl;
  EXPECT_EQ(getValue(root), "Aarti");
  EXPECT_EQ(getNextAddress(root),  nullptr);

  Link * node = createList("Deepak");
  add(root, node);
  std::cout << root<< endl;
  // First Node -> Aarti
  EXPECT_EQ(getValue(root), "Aarti");
  Link * next = getNextAddress(root);
  EXPECT_NE(next, nullptr);
  // Next Node -> Deepak
  EXPECT_EQ(getValue(next), "Deepak");
  EXPECT_EQ(getNextAddress(next),  nullptr);
  

  node = createList("Aarya");
  add(root, node);
  std::cout << root<< endl;
  // First Node -> Aarti
  EXPECT_EQ(getValue(root), "Aarti");
  next = getNextAddress(root);
  EXPECT_NE(next, nullptr);
  // Next Node -> Aarya
  EXPECT_EQ(getValue(next), "Aarya");
  EXPECT_NE(getNextAddress(next),  nullptr);
  // Next Node -> Deepak
  next = getNextAddress(next);
  EXPECT_EQ(getValue(next), "Deepak");
  EXPECT_EQ(getNextAddress(next),  nullptr);
  
  
  node = createList("Rani");
  add(root, node);
  std::cout << root<< endl;
  // First Node -> Aarti
  EXPECT_EQ(getValue(root), "Aarti");
  next = getNextAddress(root);
  EXPECT_NE(next, nullptr);
  // Next Node -> Rani
  EXPECT_EQ(getValue(next), "Rani");
  EXPECT_NE(getNextAddress(next),  nullptr);
  // Next Node -> Aarya
  next = getNextAddress(next);
  EXPECT_EQ(getValue(next), "Aarya");
  EXPECT_NE(getNextAddress(next),  nullptr);
  // Next Node -> Deepak
  next = getNextAddress(next);
  EXPECT_EQ(getValue(next), "Deepak");
  EXPECT_EQ(getNextAddress(next),  nullptr);
}