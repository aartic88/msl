#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <map>

using namespace std;
class LRUCache {
private:
  list<pair<int, int>> recent_list;
  typedef list<pair<int, int>>::iterator recent_list_iterator;
  map<int, recent_list_iterator> data;
  int capacity;

public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    auto it = data.find(key);
    if (it == data.end())
      return -1;

    int value = it->second->second;
    recent_list.erase(it->second);
    auto it2 = recent_list.insert(recent_list.begin(), make_pair(key, value));
    data[key] = it2;
    return value;
  }

  void put(int key, int value) {
    auto it = data.find(key);
    if (it != data.end()) {
      recent_list.erase(it->second);
      data.erase(key);
    }
    if (capacity == data.size()) {
      auto keyValuePair = recent_list.back();
      recent_list.pop_back();
      data.erase(keyValuePair.first);
    }
    auto it2 = recent_list.insert(recent_list.begin(), make_pair(key, value));
    data.insert(make_pair(key, it2));
  }
};
TEST(testLRUCache, basic) { // Edge {u,v,weight}
  LRUCache seq(2);          // initialize capacity
  seq.put(1,1);
  seq.put(2,2);
  EXPECT_EQ(seq.get(1),1);
  seq.put(3,3);
  EXPECT_EQ(seq.get(2),-1);
  seq.put(4,4);
  EXPECT_EQ(seq.get(1),-1);
  EXPECT_EQ(seq.get(3),3);
  EXPECT_EQ(seq.get(4),4);
}