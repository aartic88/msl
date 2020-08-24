#include "LinkedBinaryTree.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <list>
TEST(testIsList, basicTest) {
  LinkedBinaryTree<int> arr;
  arr.addRoot();
  LinkedBinaryTree<int>::Position p;
  p = arr.root(); // create Root
  *p = 34;        //assign value to root
  std::cout << *p << " "; //
  arr.expandExternal(p);  // create left and right node of root
  
  LinkedBinaryTree<int>::Position q=p.left();         
  LinkedBinaryTree<int>::Position r=p.right();

  *q=33; *r=35;

  std::cout << *q << " ";
  std::cout << *r << " ";

  std::list<LinkedBinaryTree<int>::Position> positionList= arr.positions();   //33 35 34
  for(auto it=positionList.begin(); it!=positionList.end(); it++){
    
  }
  

}