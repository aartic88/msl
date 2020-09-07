#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res = {1};
        while (res.size() < N) {
            vector<int> tmp;
            for (int i : res) if (i * 2 - 1 <= N) tmp.push_back(i * 2 - 1);
            for (int i : res) if (i * 2 <= N) tmp.push_back(i * 2);
            res = tmp;
        }
        return res;
    }
};

TEST(testbeautifulArray, basicTest) {
  Solution arr;
  vector<int> output1={2,1,4,3};
  vector<int> output2={3,1,2,5,4};

  EXPECT_EQ(output1, arr.beautifulArray(4));
  EXPECT_EQ(output2, arr.beautifulArray(5));
}