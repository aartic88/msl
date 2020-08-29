#include "doublylinklist.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(testIsLinkedList, basicTest) {
  DoublyLinkedList<std::string> greekGod;
  greekGod.addfront("zeus");
  greekGod.printlist();
  greekGod.addfront("aries");
  greekGod.printlist();
  greekGod.addfront("hades");
  greekGod.removefront();
  greekGod.printlist();
}