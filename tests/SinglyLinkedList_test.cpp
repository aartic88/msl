#include "SinglyLinkedList.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(testIsLinkedList, basicTest) {
  SinglyLinkedList greekGod;
  Node *head = greekGod.addfront("zeus");
  EXPECT_EQ(greekGod.getValue(head), "zeus");
  greekGod.printlist();

  Node *next = greekGod.addfront("aries");
  EXPECT_EQ(greekGod.getValue(next), "aries");
  greekGod.printlist();

  next = greekGod.addfront("hades");
  EXPECT_EQ(greekGod.getValue(next), "hades");
  greekGod.printlist();

  greekGod.removefront();
  greekGod.printlist();
}
