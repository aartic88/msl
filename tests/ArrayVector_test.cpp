
#include "ArrayVector.hpp"
#include "NodeList.hpp"
#include <gtest/gtest.h>
#include <iostream>
TEST(testIsArrayVector, basicTest) {
  ArrayVector arr;
  arr.insert(0, 34); // arr[0]=34
  // int a=arr.at(0);
  arr.insert(1, 23); // arr[1]=23

  arr.insert(2, 65); // arr[2]=65

  EXPECT_EQ(arr.size(), 3);
  EXPECT_EQ(arr[0], 34);
  EXPECT_EQ(arr[1], 23);
  EXPECT_EQ(arr[2], 65);
}