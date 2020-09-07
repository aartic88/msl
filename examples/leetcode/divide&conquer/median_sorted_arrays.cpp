#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int lenght = m+n;
        if(lenght%2 == 1)
            return findkth(nums1, m, nums2, n, lenght/2+1, 0, 0);
        else
            return (findkth(nums1, m, nums2, n, lenght/2, 0, 0) + findkth(nums1, m, nums2, n, lenght/2+1, 0, 0))/2;
    }
    double findkth(vector<int>& nums1, int m, vector<int>& nums2, int n, int k, int start1, int start2){
        if(m > n)
            return findkth(nums2, n, nums1, m, k, start2, start1);
        if(m == 0)
            return nums2[k-1];
        if(k == 1)
            return min(nums1[start1], nums2[start2]);
        int a = min(k/2, m);
        int b = k-a;       //k/2 Or k-m
        if(nums1[a+start1-1] <= nums2[b+start2-1]){
            return findkth(nums1, m-a, nums2, n, k-a, start1+a, start2);
        }
        else{
            return findkth(nums1, m, nums2, n-b, k-b, start1, start2+b);
        }
    }
};

TEST(testMedian2Arrays, basicTest) {
  Solution arr;
  vector<int> input1 = {1,2};
  vector<int> input2 = {3,4};

  vector<int> input3 = {};
  vector<int> input4 = {1};

  EXPECT_EQ(2.5, arr.findMedianSortedArrays(input1,input2));
  EXPECT_EQ(1, arr.findMedianSortedArrays(input3, input4));
}