#include "SinglyLinkedList.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(testIsLinkedList, basicTest) {
  SinglyLinkedList<std::string> greekGod;
  SNode<std::string> *head = greekGod.addfront("zeus");
  EXPECT_EQ(greekGod.getValue(head), "zeus");
  greekGod.printlist();

  SNode<std::string> *next = greekGod.addfront("aries");
  EXPECT_EQ(greekGod.getValue(next), "aries");
  greekGod.printlist();

  next = greekGod.addfront("hades");
  EXPECT_EQ(greekGod.getValue(next), "hades");
  greekGod.printlist();

  greekGod.removefront();
  greekGod.printlist();
}
