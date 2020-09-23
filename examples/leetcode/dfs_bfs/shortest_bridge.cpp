#include <gtest/gtest.h>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void visitFirstIsland(int i, int j, queue<pair<int, int>> &q,
                      vector<vector<int>> &A) {
  if (i < 0 or i == A.size() or j < 0 or j == A[i].size())
    return;

  if (A[i][j] == 0 or A[i][j] == 2)
    return;

  // mark first island with value 2
  q.push({i, j});
  A[i][j] = 2;

  for (int d = 0; d < 4; d++)
    visitFirstIsland(i + dirs[d].first, j + dirs[d].second, q, A);
}

int shortestBridge(vector<vector<int>> &grid) {
  queue<pair<int, int>> q;
  for (int i = 0; i < grid.size(); i++) {
    bool flag = false;
    for (int j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] == 1) {
        visitFirstIsland(i, j, q, grid);
        flag = true;
        break;
      }
    }

    // we have found and visited first island. Break out of the loop
    if (flag == true)
      break;
  }
  int distance = 0;

  while (!q.empty()) {
    int qSize = q.size();

    while (qSize--) {
      auto cur = q.front();
      q.pop();

      for (auto &dir : dirs) {
        int x = cur.first + dir.first;
        int y = cur.second + dir.second;

        if (x < 0 or x == grid.size() or y < 0 or y == grid[x].size() or
            grid[x][y] == 2)
          continue;

        if (grid[x][y] == 1)
          return distance;

        q.push({x, y});
        grid[x][y] = 2;
      }
    }

    distance++;
  }

  return -1;
}

TEST(testgrid, basicShortestPath0) {
  vector<vector<int>> twoIslands = {
      {0, 1, 0},
      {0, 0, 0},
      {0, 0, 1},
  };
  int distance = shortestBridge(twoIslands);
  cout << distance << endl;
}
TEST(testgrid, basicShortestPath1) {
  vector<vector<int>> twoIslands = {{1, 1, 1, 1, 1},
                                    {1, 0, 0, 0, 1},
                                    {1, 0, 1, 0, 1},
                                    {1, 0, 0, 0, 1},
                                    {1, 1, 1, 1, 1}};
  int distance = shortestBridge(twoIslands);
  cout << distance << endl;
}
TEST(testgrid, basicShortestPath2) {
  vector<vector<int>> twoIslands = {
      {0, 1},
      {1, 0},
  };
  int distance = shortestBridge(twoIslands);
  cout << distance << endl;
}