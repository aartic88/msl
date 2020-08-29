#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//"Integer" (one round's score): Directly represents the number of points you
// get in this round.
//"+" (one round's score): Represents that the points you get in this round are
// the sum of the last two valid round's points.
//"D" (one round's score): Represents that the points you get in this round are
// the doubled data of the last valid round's points.
//"C" (an operation, which isn't a round's score): Represents the last valid
// round's points you get were invalid and should be removed.

// Input: ["5","-2","4","C","D","9","+","+"]
// Output: 27
// Explanation:
// Round 1: You could get 5 points. The sum is: 5.
// Round 2: You could get -2 points. The sum is: 3.
// Round 3: You could get 4 points. The sum is: 7.
// Operation 1: The round 3's data is invalid. The sum is: 3.
// Round 4: You could get -4 points (the round 3's data has been removed). The
// sum is: -1. Round 5: You could get 9 points. The sum is: 8. Round 6: You
// could get -4 + 9 = 5 points. The sum is 13. Round 7: You could get 9 + 5 = 14
// points. The sum is 27.

class Solution {
public:
  int calPoints(vector<string> &ops) {
    std::stack<int> stack;
    for (int i = 0; i < ops.size(); i++) {
      if (ops[i] == "C" && !stack.empty()) {
        stack.pop();
      } else if (ops[i] == "D" && !stack.empty()) {
        stack.push(stack.top() * 2);
      } else if (ops[i] == "+" && stack.size() >= 2) {
        int last = stack.top();
        stack.pop();
        int sec_last = stack.top();
        stack.push(last);
        stack.push(last + sec_last);
      } else {
        stack.push(
            std::stoi(ops[i])); // stoi - convet a string to an signed integer
      }
    }
    int result = 0;
    while (!stack.empty()) {
      result += stack.top();
      stack.pop();
    }
    return result;
  }
};

TEST(testcalPoints, basicTest) {

  Solution arr;
  vector<std::string> input = {"5", "-2", "4", "C", "D", "9", "+", "+"};
  vector<std::string> input1 = {"5", "2", "C", "D", "+"};
  int output = arr.calPoints(input);
  std::cout << " " << output << "hellooo";
  EXPECT_EQ(27, arr.calPoints(input));
  EXPECT_EQ(30, arr.calPoints(input1));
}