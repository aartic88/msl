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

int mapper(vector<vector<int>> &snakeLadderMatrix, int i) {
    int N = snakeLadderMatrix.size();
    int NMinus = N - 1;
    int rowId = NMinus - i/N;
    int colId =  rowId % 2 ?  i%N : NMinus - i%N ;
    return snakeLadderMatrix[rowId][colId];
}

vector<vector<int>> makeAdjList(vector<vector<int>> &snakeLadderMatrix) {
  int n = snakeLadderMatrix.size();
  vector<vector<int>> graphAL(n * n);
  //vector<int> matrix1DImage = convert2Dto1D(snakeLadderMatrix);

  for (int i = 0; i < n * n; i++) {
    for (int j = i + 1; j <= i + 6 && j < n * n; j++) {
      if (mapper(snakeLadderMatrix, i) == -1 && mapper(snakeLadderMatrix, j) == -1) {
        graphAL[i].push_back(j);
      } else if (mapper(snakeLadderMatrix, i) == -1 && mapper(snakeLadderMatrix, j) != -1) {
         graphAL[i].push_back(mapper(snakeLadderMatrix, j));
      }
      if (graphAL[i].size() > 0)
      cout << i << " pushed " <<  graphAL[i][graphAL[i].size()-1] << endl; 
    }
  }
  return graphAL;
}
int snakesAndLadders(const vector<vector<int>> &snakeLadderMatrix) {
  const int numVertex = snakeLadderMatrix.size();
  int startingVertex = 0;
  vector<int> distance(numVertex, INT32_MAX);
  distance[startingVertex] = 0;
  queue<int> q;
  q.push(startingVertex);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = 0; j < (int)snakeLadderMatrix[u].size(); j++) {
      int e = snakeLadderMatrix[u][j];
      cout << u << ", "<<j << " = "<< e << endl;
      if (distance[e ] == INT32_MAX) {
        distance[e] = distance[u] + 1;
        q.push(e);
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
  EXPECT_EQ(mapper(snakeLadderMatrix, 5) , 15);
  vector<vector<int>> graphAL = makeAdjList(snakeLadderMatrix);
  EXPECT_EQ(snakesAndLadders(graphAL), 1);
    //cout  << distance << endl;
  
}
TEST(testGraph, basicShortestPath1) {
  vector<vector<int>> snakeLadderMatrix = {
      {-1, -1, -1, -1, -1, -1}, 
      {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1}, 
      {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1}, 
      {-1, 15, -1, -1, -1, -1}};

  EXPECT_EQ(mapper(snakeLadderMatrix, 13) , 35);
  EXPECT_EQ(mapper(snakeLadderMatrix, 1) , 15); 
  EXPECT_EQ(mapper(snakeLadderMatrix, 16) , 13);   
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

  cout <<    snakeLadderMatrix[0][5]; 
  vector<vector<int>> graphAL = makeAdjList(snakeLadderMatrix);
  int distance = snakesAndLadders(graphAL);
    cout  << distance << endl;
  
}