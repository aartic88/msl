#include <gtest/gtest.h>
#include <vector>
using namespace std;

class Solution {
public:
  void islandDFS(std::vector<std::vector<char>> &grid, int i, int j) {
    grid[i][j] = '0';            // marked visited
    if ((i + 1) < grid.size()) { // south
      if (grid[i + 1][j] == '1') {
        islandDFS(grid, i + 1, j);
      }
    }
    if ((j + 1) < grid[0].size()) { // east
      if (grid[i][j + 1] == '1') {
        islandDFS(grid, i, j + 1);
      }
    }
    if ((i - 1) >= 0) { // north
      if (grid[i - 1][j] == '1') {
        islandDFS(grid, i - 1, j);
      }
    }
    if ((j - 1) >= 0) {
      if (grid[i][j - 1] == '1') { // west
        islandDFS(grid, i, j - 1);
      }
    }
  }
  int numIslands(std::vector<std::vector<char>> &grid) {
    int counter = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          counter++;
          islandDFS(grid, i, j);
        }
      }
    }
    return counter;
  }
};

TEST(testgrid2, numOfIslands1) {
  Solution s;
  vector<vector<char>> islands = {
      {'0', '1'},
      {'1', '0'},
  };
  int count = s.numIslands(islands);
  cout << count << endl;
  EXPECT_EQ(count, 2);
}

TEST(testgrid2, numOfIslands2) {
  Solution s;
  vector<vector<char>> islands = {
      {'0', '1'},
      {'0', '0'},
  };
  int count = s.numIslands(islands);
  cout << count << endl;
  EXPECT_EQ(count, 1);
}

TEST(testgrid2, numOfIslands3) {
  Solution s;
  vector<vector<char>> islands = {
      {'1', '1', '1', '1', '1'}, {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '0', '0'}, {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '0', '1'},
  };
  int count = s.numIslands(islands);
  cout << count << endl;
}

TEST(testgrid2, numOfIslands4) {
  Solution s;
  vector<vector<char>> islands = {
      {'1', '1', '1', '1', '1'}, {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
  };
  int count = s.numIslands(islands);
  cout << count << endl;
}