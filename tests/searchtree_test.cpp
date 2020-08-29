#include "searchtree.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <list>
TEST(testIsList, basicTest) {
SearchTree<Entry<int,int>> tree;
tree.insert(1,44);
tree.insert(2,88);
tree.insert(3,17);
tree.insert(4,32);
tree.insert(5,97);
tree.insert(6,65);
tree.insert(7,28);
tree.insert(8,29);
tree.insert(9,82);
tree.insert(10,54);
tree.insert(11,76);
tree.insert(12,80);
tree.insert(13,78);

SearchTree<Entry<int,int>>::Iterator p=tree.find(4);
int q=(*p).value();
std::cout<<q;      //??????????compiles but no output??????



}