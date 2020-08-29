#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// {4, 1, 2} is subset of {1, 3, 4, 2}
// find next greater number in superset if not found then replace with -1
// output - {-1,3,-1}

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size();
    if (nums1.size() == 0) {
      vector<int> result = {};
      return result;
    }

    vector<int> result(n1, -1);
    int found = 0;

    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        if (nums1[i] == nums2[j]) {
          found = j;

          break;
        }
      }

      for (int k = found; k < nums2.size(); k++) {
        if (nums2[k] > nums1[i]) {
          result[i] = nums2[k];

          break;
        }
      }
    }

    return result;
  }
};

//[{3,1,5,7,9,2,6}{1,2,3,5,6,7,9,11}]
//[{4, 1, 2},{1, 3, 4, 2}

TEST(nextGreaterElement, basicTest) {
  Solution arr;
  vector<int> nums1 = {3, 1, 5, 7, 9, 2, 6};
  vector<int> nums2 = {1, 2, 3, 5, 6, 7, 9, 11};
  vector<int> output = {5, 2, 6, 9, 11, 3, 7};
  EXPECT_EQ(output, arr.nextGreaterElement(nums1, nums2));
}

TEST(nextGreaterElement, emptySubsetTest) {
  Solution arr;
  vector<int> nums1 = {};
  vector<int> nums2 = {1, 2, 3, 5, 6, 7, 9, 11};
  vector<int> output = {};
  EXPECT_EQ(output, arr.nextGreaterElement(nums1, nums2));
}
TEST(nextGreaterElement, basicTest1) {
  Solution arr;
  vector<int> nums1 = {{4, 1, 2}};
  vector<int> nums2 = {1, 3, 4, 2};
  vector<int> output = {-1, 3, -1};
  EXPECT_EQ(output, arr.nextGreaterElement(nums1, nums2));
}