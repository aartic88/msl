#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  string makeGood(string s) {
    for (int i = 0; i < s.length(); i++) {
      if (abs(s[i] - s[i + 1]) == 32) {
        s = s.substr(0, i) + s.substr(i + 2, s.length());
        if (i < 1) {
          i--;
        } else {
          i -= 2;
        }
        // makeGood(s.substr(0,i)+s.substr(i+2,s.length()));
      }
    }
    return s;
  }
};

TEST(testcalPoints, basicTest) {

  Solution arr;
  std::string input = "leEeetcode";
  std::string input1 = "abBAcC";
  // std::string output = arr.makeGood(input);
  // std::string output1 = arr.makeGood(input1);
  // std::cout << " " << output << "hellooo";
  EXPECT_EQ("leetcode", arr.makeGood(input));
  EXPECT_EQ("", arr.makeGood(input1));
}