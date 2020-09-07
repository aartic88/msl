#include <gtest/gtest.h>
#include <iostream>
#include <stack>

using namespace std;
//  (()())(()) -> ()()()   & (()(())) -> ()(())
// Return S after removing the outermost parentheses of
// every primitive string in the primitive decomposition of S
class Solution {
public:
  string removeOuterParentheses(string S) {
    std::stack<char> stack;
    std::string newS;
    for (int i = 0; i < S.length(); i++) {
      if (S[i] == '(') {
        if (stack.size() > 0) {
          newS += '(';
        }
        stack.push('(');
      } else {
        if (stack.size() > 1) {
          newS += ')';
        }
        stack.pop();
      }
    }
    return newS;
  }
};

TEST(testremoveOuterParentheses, basicTest) {
  Solution arr;
  std::string input1 = "(()())(())";
  std::string output1 = "()()()";
  EXPECT_EQ("()()()", arr.removeOuterParentheses("(()())(())"));
  EXPECT_EQ("()(())", arr.removeOuterParentheses("(()(()))"));
  EXPECT_EQ(output1, arr.removeOuterParentheses(input1));
}