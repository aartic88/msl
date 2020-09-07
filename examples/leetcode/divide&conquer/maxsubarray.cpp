
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int prev = A[0], curr=A[0];
        for (int i = 1; i < A.size(); i++){
            prev+=A[i];
            prev=max(prev,A[i]);
            curr=max(curr,prev);
        }
        return curr;
    }
};

TEST(testmaxSubArray, basicTest) {
  Solution arr;
  vector<int> input1 = {-2,1};
  vector<int> input2 = {1,2};
  vector<int> input3 = {2};
  vector<int> input4 = {-2,1,-3,4,-1,2,1,-5,4};

  EXPECT_EQ(1, arr.maxSubArray(input1));
  EXPECT_EQ(3, arr.maxSubArray(input2));
  EXPECT_EQ(2, arr.maxSubArray(input3));
  EXPECT_EQ(6, arr.maxSubArray(input4));
}