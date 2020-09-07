
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

//-----A pair (i,j) is called good if nums[i] == nums[j] and i < j.

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size();j++){
                if(nums[i]==nums[j])
                count++;
            }
        }
        return count;
    }
};

TEST(testmaxSubArray, basicTest) {
  Solution arr;
  vector<int> input1 = {1,2,3,1,1,3};
  vector<int> input2 = {1,1,1,1};
  vector<int> input3 = {1,2,3};
  //vector<int> input4 = {-2,1,-3,4,-1,2,1,-5,4};

  EXPECT_EQ(4, arr.numIdenticalPairs(input1));
  EXPECT_EQ(6, arr.numIdenticalPairs(input2));
  EXPECT_EQ(0, arr.numIdenticalPairs(input3));
  //EXPECT_EQ(6, arr.maxSubArray(input4));
}