#include "CircularlyLinkedList.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(testIsLinkedList, basicTest) {
  CircularlyLinkedList<std::string> greekGod;
  greekGod.add("zeus");
  greekGod.printlist();
  greekGod.add("aries");
  greekGod.printlist();
  greekGod.add("hades");
  greekGod.printlist();
  // cout<<greekGod.size();
}