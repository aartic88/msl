#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    /*if (nums.size() == 1) {
      return nums[0];
    }
    for (int x : nums) {
      std::cout << x << " ";
    }
    int count = 1, majority = 0, n = nums.size();
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        count++;
        std::cout << n / 2 << " ";
        if (count > n / 2) {
          std::cout << count << " ";
          majority = nums[i];
        }
      } else {
        count = 1;
      }
    }*/
    return nums[nums.size()/2];
  }
};

TEST(testmajorityElement, basicTest) {
  Solution arr;
  vector<int> input1 = {3, 2, 3};
  vector<int> input2 = {2, 2, 1, 1, 1, 2, 2};
  vector<int> input3 = {2};

  EXPECT_EQ(3, arr.majorityElement(input1));
  EXPECT_EQ(2, arr.majorityElement(input2));
  EXPECT_EQ(2, arr.majorityElement(input3));
}