#include "hashmap.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <list>
TEST(testIsList, basicTest) {
  HashMap<int ,int> arr;
  arr.put(1,35);
  arr.put(2,45);
  arr.put(3,25);
  arr.put(4,65);
  arr.put(5,15);
  arr.put(6,85);
}