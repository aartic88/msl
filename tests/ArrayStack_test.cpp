#include "ArrayStack.hpp"
#include "ArrayQueue.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(testIsLinkedList, basicTest) {
  ArrayStack greekGod;
  greekGod.push(345);
  greekGod.push(23);
  greekGod.push(67);
  greekGod.print();
  greekGod.pop();
  greekGod.print();
  cout << greekGod.top();
}
TEST(testArrayQueue, basicTest) {
  ArrayQueue greekGod;
  greekGod.enqueue(345);
  greekGod.enqueue(23);
  greekGod.enqueue(67);
  cout << greekGod.front();
  greekGod.print();
  greekGod.dequeue();
  greekGod.print();
  cout << greekGod.front();
}