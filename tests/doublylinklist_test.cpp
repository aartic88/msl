#include "doublylinklist.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(testIsLinkedList, basicTest) {
  DoublyLinkList greek_god;
  greek_god.addfront("zeus");
  greek_god.printlist();
  greek_god.addfront("aries");
  greek_god.printlist();
  greek_god.addfront("hades");
  greek_god.printlist();
}