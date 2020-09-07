#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    return searchMatrix(matrix, target, 0, matrix.size() - 1);
  }

  bool searchMatrix(vector<vector<int>> &matrix, int target, int top,
                    int bottom) {
    if (top > bottom)
      return false;

    int mid = top + (bottom - top) / 2;
    if (matrix[mid].front() <= target && target <= matrix[mid].back())
      if (searchVector(matrix[mid], target))
        return true;

    if (searchMatrix(matrix, target, top, mid - 1))
      return true;
    if (searchMatrix(matrix, target, mid + 1, bottom))
      return true;

    return false;
  }

  bool searchVector(vector<int> &v, int target) {
    int left = 0, right = v.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (v[mid] == target)
        return true;
      if (v[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }

    return false;
  }
};
TEST(testSearchMatrix, basicTest) {
  Solution arr;
  vector<vector<int>> input1 = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
  vector<vector<int>> input2 = {};
  vector<vector<int>> input3 = {{}};
  EXPECT_EQ(true, arr.searchMatrix(input1, 5));
  EXPECT_EQ(false, arr.searchMatrix(input1, 20));
  EXPECT_EQ(false, arr.searchMatrix(input2, 1));
  EXPECT_EQ(false, arr.searchMatrix(input3, 1));
}
