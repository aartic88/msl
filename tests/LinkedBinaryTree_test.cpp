#include "LinkedBinaryTree.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <list>
TEST(testIsList, basicTest) {
  LinkedBinaryTree arr;
  arr.addRoot();
  LinkedBinaryTree::Position p;
  p = arr.root(); // create Root
  *p = 34;
  std::cout << *p << " "; //
  arr.expandExternal(p);  // create left and right node of root
}