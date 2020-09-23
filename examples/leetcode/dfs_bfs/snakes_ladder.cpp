#include <gtest/gtest.h>
#include <queue>
#include <vector>
using namespace std;

/*
pair<int, int> coordinates(int curr, int size)
{
    int r = size - (curr - 1) / size - 1;
    int c = (curr - 1) % size;
    if (r % 2 == size % 2)
        return make_pair(r, size - 1 - c);
    return make_pair(r, c);
}

int bfs(const vector<vector<int>> &snakeLadderMatrix)
{
    int steps = 0;
    int numRow = snakeLadderMatrix.size();
    vector<bool> visited(numRow*numRow + 1, false);
    visited[1] = true;

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int qsize = q.size();
        while (qsize--)
        {
            int current = q.front();
            if (current == numRow * numRow)
                return steps;
            q.pop();

            for (int j = 1; j <= 6; j++)
            {
                if (current + j > numRow*numRow)
                    break;
                if (!visited[current + j])
                {
                    pair<int, int> rc = coordinates(current + j, numRow);
                    visited[current + j] = true;
                    if (snakeLadderMatrix[rc.first][rc.second] == -1)
                        q.push(current + j);
                    else
                        q.push(snakeLadderMatrix[rc.first][rc.second]);
                }
            }
        }
        steps++;
    }
    return -1;
}
*/

vector<int> convert2Dto1D(vector<vector<int>> snakeLadderMatrix) {
  int n = snakeLadderMatrix.size();
  for (int i = 1; i < n; i += 2) {
    if (n % 2 == 0)
      reverse(snakeLadderMatrix[i].begin(), snakeLadderMatrix[i].end());
    else
      reverse(snakeLadderMatrix[i - 1].begin(), snakeLadderMatrix[i - 1].end());
  }
  vector<int> matrix1Dimage;
  for (int i = n - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--)
      matrix1Dimage.push_back(snakeLadderMatrix[i][j]);
  return matrix1Dimage;
}

vector<vector<int>> makeAdjList(vector<vector<int>> &snakeLadderMatrix) {
  int n = snakeLadderMatrix.size();
  vector<vector<int>> graphAL(n * n);
  vector<int> matrix1DImage = convert2Dto1D(snakeLadderMatrix);

  for (int i = 0; i < n * n; i++) {
    for (int j = i + 1; j <= i + 6 && j < n * n; j++) {
      if (matrix1DImage[i] != -1) {
        graphAL[i].push_back(matrix1DImage[i]);
        break;
      } else {
        if (matrix1DImage[j] == -1) {
          graphAL[i].push_back(j + 1);
        } else {
          graphAL[i].push_back(matrix1DImage[j]);
        }
      }
    }
  }
  return graphAL;
}
int snakesAndLadders(vector<vector<int>> &snakeLadderMatrix) {
  int numVertex = snakeLadderMatrix.size();
  int startingVertex = 1;
  vector<int> distance(numVertex, INT32_MAX);
  distance[startingVertex - 1] = 0;
  queue<int> q;
  q.push(startingVertex);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = 0; j < (int)snakeLadderMatrix[u - 1].size(); j++) {
      int e = snakeLadderMatrix[u - 1][j];
      if (distance[e - 1] == INT32_MAX) {
        distance[e - 1] = distance[u - 1] + 1;
        q.push(e);
        cout << e;
      }
    }
  }
  return distance[numVertex-1];
}
TEST(testGraph, basicShortestPath0) {
  vector<vector<int>> snakeLadderMatrix = {{
                                               -1,
                                               -1,
                                               -1,
                                               -1,
                                           },
                                           {
                                               5,
                                               -1,
                                               -1,
                                               -1,
                                           },
                                           {
                                               -1,
                                               -1,
                                               15,
                                               -1,
                                           },
                                           {
                                               -1,
                                               11,
                                               -1,
                                               -1,
                                           }};
  vector<vector<int>> graphAL = makeAdjList(snakeLadderMatrix);
  int distance = snakesAndLadders(graphAL);
    cout  << distance << endl;
  
}
TEST(testGraph, basicShortestPath1) {
  vector<vector<int>> snakeLadderMatrix = {
      {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
  vector<vector<int>> graphAL = makeAdjList(snakeLadderMatrix);
  int distance = snakesAndLadders(graphAL);
    cout  << distance << endl;
  
}
TEST(testGraph, basicShortestPath2) {
  vector<vector<int>> snakeLadderMatrix = {
      {-1, -1},
      {-1, 3},
  };
  vector<vector<int>> graphAL = makeAdjList(snakeLadderMatrix);
  int distance = snakesAndLadders(graphAL);
    cout  << distance << endl;
  
}
TEST(testGraph, basicShortestPath3) {
  vector<vector<int>> snakeLadderMatrix = {
      {4, -1, -1}, {-1, -1, -1}, {-1, 8, -1}};
  vector<vector<int>> graphAL = makeAdjList(snakeLadderMatrix);
  int distance = snakesAndLadders(graphAL);
    cout  << distance << endl;
  
}