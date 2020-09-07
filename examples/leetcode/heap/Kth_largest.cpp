#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
  priority_queue<int, vector<int>, greater<int>> pq;  //smallest element at top..
  int size;
  KthLargest(int k, vector<int> &nums) {
    size = k;
    for (int i = 0; i < nums.size(); i++) {
      pq.push(nums[i]);
      if (pq.size() > k)
        pq.pop();
        //std::cout << " "<<pq.top();
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > size)
      pq.pop();
    return pq.top();
  }
};

TEST(testKthLargest, basicTest) {

  int k = 3;
  vector<int> arr = {4, 5, 8, 2};
  KthLargest kthLargest = KthLargest(3, arr);
  std::cout << " "<<(kthLargest.add(3)) ; // returns 4
  std::cout << " "<<kthLargest.add(5);  // returns 5
  std::cout << " "<<kthLargest.add(10); // returns 5
  std::cout << " "<<(kthLargest.add(9));  // returns 8
  std::cout << " "<<kthLargest.add(4);  // returns 8

  // EXPECT_EQ(1, arr.lastStoneWeight(input));
}
