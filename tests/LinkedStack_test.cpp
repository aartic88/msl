#include "LinkedStack.hpp"
#include "LinkedDeque.hpp"
#include "LinkedQueue.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(testIsLinkedList, basicTest) {
  LinkedStack greekGod;
  greekGod.push("345");
  greekGod.push("23");
  greekGod.push("67");
  greekGod.print();
  greekGod.pop();
  greekGod.print();
  greekGod.pop();
  //greekGod.pop();
  cout << greekGod.top();
}