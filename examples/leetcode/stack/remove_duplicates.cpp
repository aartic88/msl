#include <iostream>
#include <stack>
#include <string>
using namespace std;

// abbaca->aaca->ca

class Solution {
public:
  string removeDuplicates(string S) {
    std::stack<char> stack;

    // stack.push('0');
    stack.push(S[0]);
    for (int i = 1; i < S.length(); i++) {
      if (!stack.empty() && stack.top() == S[i]) {
        stack.pop();
      } else {
        stack.push(S[i]);
      }
    }
    std::string result;
    while (!stack.empty()) {
      result = stack.top() + result;
      stack.pop();
    }

    return result;
  }
};
int main() {
  Solution arr;
  std::string input = "abbaca";
  std::string output1 = arr.removeDuplicates(input);

  std::cout << " " << output1;
}
