
#include "NodeList.hpp"
#include <gtest/gtest.h>
#include <iostream>
TEST(testIsList, basicTest) {
  NodeList arr;
  arr.insertFront(34);
  arr.insertFront(23);

  arr.insertFront(65);

  EXPECT_EQ(arr.size(), 3);
  NodeList::Iterator p = arr.begin();
  EXPECT_EQ(*p, 65);
  // ++p;
  EXPECT_EQ(*p, 23);
  // p++;
  EXPECT_EQ(*p, 34);
}