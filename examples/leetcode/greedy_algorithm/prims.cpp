#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct compare {
  bool operator()(vector<int> const &a, vector<int> const &b) {
    return a[2] > b[2];
  }
};

vector<vector<int>> makeWeightedMatrix(vector<vector<int>> graph,
                                       int numVertex) {
  vector<vector<int>> weightedMatrix(numVertex, vector<int>(numVertex, 0));
  for (int i = 0; i < graph.size(); i++) {
    weightedMatrix[graph[i][0]][graph[i][1]] = graph[i][2];
    weightedMatrix[graph[i][1]][graph[i][0]] = graph[i][2];
  }
  return weightedMatrix;
}
int shortestPath(vector<vector<int>> weightedMatrix) {
  vector<bool> reached(weightedMatrix.size(), false);
  vector<int> path;
  int sum = 0;
  int size = weightedMatrix.size();
  int startingPoint = 0;
  reached[startingPoint] = true;
  path.push_back(startingPoint);
  priority_queue<vector<int>, vector<vector<int>>, compare> pQueue;
  for (int i = 0; i < size; i++) { // inserting egdes adjacent to startingPoint
    if (weightedMatrix[startingPoint][i] != 0) {
      pQueue.push({startingPoint, i, weightedMatrix[startingPoint][i]});
    }
  }
  while (!pQueue.empty()) {
    auto edge = pQueue.top();
    int otherVertex = edge[1];
    for (int i = 0; i < size; i++) {
      if (weightedMatrix[otherVertex][i] != 0) {
        if (reached[i] == 0)
          pQueue.push(
              {otherVertex, i,
               weightedMatrix[otherVertex]
                             [i]}); // inserting othervertex of minimun egde
        else
          pQueue.pop(); // removing visited edge
                        // need to change : delete current edge not the top
                        // egde...
      }
    }
    reached[otherVertex] = true;
    path.push_back(otherVertex);
    sum += edge[2];
  }
  return sum;
}

TEST(testGraph, basicshortestPath) { // Edge {u,v,weight}
  vector<vector<int>> prereq1 = {{0, 1, 1}, {0, 2, 3},  {0, 3, 11}, {1, 4, 9},
                                 {1, 5, 8}, {1, 2, 2},  {2, 5, 7},  {2, 3, 13},
                                 {2, 6, 5}, {3, 7, 10}, {6, 7, 4},  {5, 6, 6},
                                 {4, 5, 12}};
  vector<vector<int>> weightedMatrix = makeWeightedMatrix(prereq1, 9);
  int sum = shortestPath(weightedMatrix);
  EXPECT_EQ(sum, 37);
}
/*
TEST(testGraph, basicshortestPath2) { // Edge {u,v,weight}
   vector<vector<int>> prereq1 = {{0, 1, 4},  {0, 7, 6},  {1, 2, 8}, {1, 7,
     11}, {2, 3, 7},  {2, 8, 3},  {2, 5, 4}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10},
     {5, 6, 2}, {6, 8, 6}, {6, 7, 1},  {7, 8, 7}};
  vector<vector<int>> weightedMatrix = makeWeightedMatrix(prereq1, 9);
  int sum = shortestPath(weightedMatrix);
  EXPECT_EQ(sum,36);
}
*/