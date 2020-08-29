#include <iostream>
#include <vector>

using namespace std;
/*
Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation:
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]
*/
class Solution {
public:
  vector<std::string> buildArray(vector<int> &target, int n) {
    vector<std::string> result;
    int j = 0;
    for (int i = 1; i != target.back() + 1; i++) {
      while (j < i) {
        if (target[j] == i) {
          result.push_back("Push");
          j++;
          break;
        }
        if (target[j] != i) {
          result.push_back("Push");
          result.push_back("Pop");
          break;
        }
      }
    }
    return result;
  }
};
int main() {
  Solution arr;
  vector<int> input = {2, 3, 4};
  vector<std::string> output1 = arr.buildArray(input, 4);
  for (int x : input)
    std::cout << x;
  for (std::string x : output1)
    std::cout << x << " ";
}