#include "LinkedStack.hpp"
#include "LinkedDeque.hpp"
#include "LinkedQueue.hpp"
#include <gtest/gtest.h>
using namespace std;
TEST(testIsLinkedList, StackTest) {
  LinkedStack<int> greekGod;
  greekGod.push(345);
  greekGod.push(23);
  greekGod.push(67);
  greekGod.print();
  greekGod.pop();
  greekGod.print();
  //greekGod.pop();
  //greekGod.pop();
  cout << greekGod.top();
}
TEST(testIsLinkedList, DequeTest) {
  LinkedDeque<std::string> greekGod;
  greekGod.insertfront("345");
  greekGod.insertfront("23");
  greekGod.insertfront("67");
  greekGod.print();
  greekGod.removefront();
  greekGod.print();
  greekGod.removefront();
  //greekGod.removeback();
  cout << greekGod.front();
}
TEST(testIsLinkedList, QueueTest) {
  LinkedQueue<std::string>  greekGod;
  greekGod.enqueue("345");
  greekGod.enqueue("23");
  greekGod.enqueue("67");
  greekGod.print();
  greekGod.dequeue();
  greekGod.print();
  //greekGod.pop();
  //greekGod.pop();
  cout << greekGod.front();
}