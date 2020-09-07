#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int left = 0, right = nums.size() - 1, kth;
    while (true) {
      int idx = partition(nums, left, right);
      if (idx == k - 1) {
        kth = nums[idx];
        break;
      }
      if (idx < k - 1) {
        left = idx + 1;
      } else {
        right = idx - 1;
      }
    }
    return kth;
  }

private:
  int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left], l = left + 1, r = right;
    while (l <= r) {
      if (nums[l] < pivot && nums[r] > pivot) {
        swap(nums[l++], nums[r--]);
    
        for (int x : nums) {
          cout << x << " ";
        }
      }
      if (nums[l] >= pivot) {
        l++;
      }
      if (nums[r] <= pivot) {
        r--;
      }
    }
    swap(nums[left], nums[r]);
    for (int x : nums) {
      cout << x << " ";
    }
    cout << endl;
    return r;
  }
};

TEST(testkthLargetst, basicTest) {
  Solution arr;
  vector<int> input1 = {3, 2, 1, 5, 6, 4};

  vector<int> input2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};

  EXPECT_EQ(5, arr.findKthLargest(input1, 2));
  EXPECT_EQ(4, arr.findKthLargest(input2, 4));
}