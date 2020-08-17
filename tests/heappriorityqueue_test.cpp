#include "heappriorityqueue.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(testIsList, basicTest) {
  HeapPriorityQueue<int, isLess<int>> arr;

  arr.insert(5);
  arr.insert(6);
  EXPECT_EQ(arr.min(), 5);
  arr.insert(3);
  EXPECT_EQ(arr.min(), 3);
  arr.insert(2);

  EXPECT_EQ(arr.min(), 2);
}