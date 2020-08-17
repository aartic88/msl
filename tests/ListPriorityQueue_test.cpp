#include "ListPriorityQueue.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <list>
TEST(testIsList, basicTest) {
  ListPriorityQueue<int,isLess<int>> arr;
  //ListPriorityQueue<int,isLessInt> arr;

  arr.insert(5);
  arr.insert(2);

  EXPECT_EQ(arr.min(), 2);
  arr.removeMin();

  arr.insert(8);
  arr.insert(6);

  EXPECT_EQ(arr.min(), 5);
  EXPECT_EQ(arr.size(), 3);
}