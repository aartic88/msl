#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int l = 0, r = points.size() - 1;
        while (true) {
            int p = partition(points, l, r);
            if (p == K - 1) {
                break;
            }
            if (p < K - 1) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }

        return std::vector<vector<int>>(points.begin(), points.begin() + K);
    }
private:
    bool farther(vector<int>& p, vector<int>& q) {
        return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
    }
    
    bool closer(vector<int>& p, vector<int>& q) {
        return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = left, l = left + 1, r = right;
        while (l <= r) {
            if (farther(points[l], points[pivot]) && closer(points[r], points[pivot])) {
                swap(points[l++], points[r--]);
            }
            if (!farther(points[l], points[pivot])) {
                l++;
            }
            if (!closer(points[r], points[pivot])) {
                r--;
            }
        }
        swap(points[pivot], points[r]);
        return r;
    }
};

TEST(testkClosest, basicTest) {
  Solution arr;
  vector<vector<int>> input1 = {{1,3},{-2,2}};
  vector<vector<int>> output1 = {{-2,2}};
  vector<vector<int>> input2 = {{3,3},{5,-1},{-2,4}};
    vector<vector<int>> output2={{3,3},{-2,4}};

  EXPECT_EQ(output1, arr.kClosest(input1,1));
  EXPECT_EQ(output2, arr.kClosest(input2,2));
}
