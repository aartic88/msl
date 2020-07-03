#include "Singlylinklist.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(testIsLinkedList, basicTest) {
  Singlylinklist greek_god;
  Node *head = greek_god.addfront("zeus");
  EXPECT_EQ(greek_god.getValue(head), "zeus");
  greek_god.printlist();

  Node *next = greek_god.addfront("aries");
  EXPECT_EQ(greek_god.getValue(next), "aries");
  greek_god.printlist();

  next = greek_god.addfront("hades");
  EXPECT_EQ(greek_god.getValue(next), "hades");
  greek_god.printlist();
}
