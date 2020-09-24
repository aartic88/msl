#include <vector>
#include <map>
#include <queue>
#include <set>
#include <gtest/gtest.h>
using namespace std;

class Solution {
private:
    int cellNumber(int i, int j, int N) {
       if (i < 0 || j < 0 || i >=N || j>=N) return -1;
       return i * N + j; 
    }
    
    vector<vector<int>>  createGraph(vector<vector<int>>& A, bool oneOnly) {
        int N = A.size();
        vector<vector<int>> adjList(N*N);
        
        for (int i = 0; i<A.size();i++) {
            for (int j = 0; j<A[i].size();j++) {
                
                int x1 = i - 1;
                int x2 = i + 1;
                
                int y1 = j - 1;
                int y2 = j + 1;
                
                int cellId = cellNumber(i, j, N);
                
                int newCellNumber;

                if (oneOnly && A[i][j] == 0) // If A[i][j] == 0 then we dont want to do anything with this vertex
                 continue;
                // You start at top left
                newCellNumber = cellNumber(i, y1, N);  // Left
                if (newCellNumber != -1) {
                    if (!oneOnly || (oneOnly && A[i][y1] == 1)) {
                        adjList[cellId].push_back(newCellNumber);
                        adjList[newCellNumber].push_back(cellId); 
                    }
                }
                
                newCellNumber = cellNumber(i, y2, N);  // Right
                if (newCellNumber != -1) {
                     if (!oneOnly || (oneOnly && A[i][y2] == 1)) {
                        adjList[cellId].push_back(newCellNumber);
                        adjList[newCellNumber].push_back(cellId);
                     }
                }
                
                newCellNumber = cellNumber(x1, j, N);  //Up
                if (newCellNumber != -1) {
                    if (!oneOnly || (oneOnly && A[x1][j] == 1)) {
                        adjList[cellId].push_back(newCellNumber);
                        adjList[newCellNumber].push_back(cellId);
                    }
                }
                
                newCellNumber = cellNumber(x2, j, N);  // Down
                if (newCellNumber != -1) {
                    if (!oneOnly || (oneOnly && A[x2][j] == 1)) {
                        adjList[cellId].push_back(newCellNumber);
                        adjList[newCellNumber].push_back(cellId);
                    }
                }
            }
        }
        return adjList;
    }
    
    void noOfConnectedComponents(const vector<vector<int>> & graph, vector<int> & connectedComponents) {
        
        int connectComponentNumber = 1;
        for (int i = 0;i<connectedComponents.size(); i++) {
            if (connectedComponents[i] == 0) {
                bfs(graph, connectedComponents, i, connectComponentNumber++);
            }
        }
    }
    
    vector<int> bfs (const vector<vector<int>> & graph, vector<int> & connectedComponents, int startingVertex, int connectComponentNumber) {
        // inside int main()---no recursion
        vector<int> distance(graph.size(), INT32_MAX);
        distance[startingVertex] = 0;
        queue<int> q; 
        q.push(startingVertex);
        // distance from source s to s is 0
        // start from source
        while (!q.empty()) {
            int u = q.front(); q.pop();
            connectedComponents[u] = connectComponentNumber;
            // queue: layer by layer!
            for (int j = 0; j < (int)graph[u].size(); j++) {
                int otherVertex = graph[u][j];
                // for each neighbor of u
                if (distance[otherVertex] == INT32_MAX) {
                    // if v.first is unvisited + reachable
                    distance[otherVertex] = distance[u] + 1;
                    // make d[v.first] != INF to flag it
                    q.push(otherVertex);
                    // enqueue v.first for the next iteration
                }
            }
        }
        return distance;
    }
    
    
    void reduceGraph(vector<vector<int>>& adjList, map<int, vector<int>> & connectedComponentMap) {
        map<int, int> vertexToFirstVertexMap; 
        for (auto it = connectedComponentMap.begin(); it!= connectedComponentMap.end(); it++) {
            int firstVertexOfIsland = it->second[0];
            // Notice the reference we dont want a copy of adJListOfFirstVertex as we want to modify the graph
            vector<int> & adJListOfFirstVertex = adjList[firstVertexOfIsland];   
            set<int> ss;
            // Insrt all the elements of adJListOfFirstVertex in set ss. 
            ss.insert(adJListOfFirstVertex.begin(), adJListOfFirstVertex.end());
            auto it2 = it->second.begin();
            it2++;
            for (; it2 != it->second.end(); it2++){
                int vertexToMerge =  *it2;
                vertexToFirstVertexMap[vertexToMerge] = firstVertexOfIsland;
                vector<int> & adJListOfVertex =  adjList[vertexToMerge];  // Avoid duplication of vector using reference
                ss.insert(adJListOfVertex.begin(), adJListOfVertex.end());
            }
            adJListOfFirstVertex.resize(0);
            ss.erase(firstVertexOfIsland);  //remove  i -> i
            adJListOfFirstVertex.insert(adJListOfFirstVertex.begin(), ss.begin(), ss.end());
        }

        for (int i = 0; i< adjList.size(); i++) {
            for (int j = 0; j< adjList[i].size(); j++) {
                //Find all the edges endpoint to 1s 
                if (vertexToFirstVertexMap.find(adjList[i][j]) != vertexToFirstVertexMap.end()) {
                    // Replace with firstVertex Of Connected Component
                    adjList[i][j] = vertexToFirstVertexMap[adjList[i][j]];   
                }
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        // We are creating a graph of 1 only which are connected to each other up, down left , right, zeroes are ignored
        vector<vector<int>> adjList = createGraph(A, true);
        int N = A.size();
        vector<int> connectedComponents(N * N, 0);
        // Now we are trying to find the connected components we should get two island of 1s with one or more element.
        noOfConnectedComponents(adjList, connectedComponents);
        // connectedComponentMap stores the two islands list island1 -> [...] and island2 -> [...]
        map<int, vector<int>> connectedComponentMap;
        for (int i = 0; i< A.size(); i++) {
            for (int j = 0; j< A[i].size();j++) {
                if (A[i][j] == 1) {
                    int cellId = cellNumber(i, j, N);
                    connectedComponentMap[connectedComponents[cellId]].push_back(cellId); 
                }
            }
        }
        // Create a graph of 0s and 1s connected eachother up, down, left right directtion
        adjList = createGraph(A, false);
        reduceGraph(adjList, connectedComponentMap);
        auto connectedComponentMapIterator = connectedComponentMap.begin();
        int firstVertexOfIsland1 =  *connectedComponentMapIterator->second.begin();
        connectedComponentMapIterator++;
        int firstVertexOfIsland2 =  *connectedComponentMapIterator->second.begin();
        vector<int> distance = bfs(adjList, connectedComponents, firstVertexOfIsland1, 1);
        return distance[firstVertexOfIsland2];
    }
};

TEST(testgrid2, basicShortestPath1) {
  Solution s;
  vector<vector<int>> twoIslands = {
      {0, 1},
      {1, 0},
  };
  int distance = s.shortestBridge(twoIslands);
  cout << distance << endl;
}

TEST(testgrid2, basicShortestPath2) {
  Solution s;
  vector<vector<int>> twoIslands = {
      {0, 0, 0, 1, 1},
      {1, 0, 0, 0, 1},
      {1, 0, 0, 0, 1},
      {1, 0, 1, 1, 1},
      {1, 0, 0, 0, 0},
  };
  int distance = s.shortestBridge(twoIslands);
  cout << distance << endl;
}

TEST(testgrid2, basicShortestPath3) {
  Solution s;
  vector<vector<int>> twoIslands = {
      {1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1},
      {1, 0, 0, 0, 1},
  };
  int distance = s.shortestBridge(twoIslands);
  cout << distance << endl;
}

TEST(testgrid2, basicShortestPath4) {
  Solution s;
  vector<vector<int>> twoIslands = {
      {1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {1, 1, 0, 0, 0},
  };
  int distance = s.shortestBridge(twoIslands);
  cout << distance << endl;
}