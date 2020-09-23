#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

class Solution {
private:
    int cellNumber(int i, int j, int N) {
       if (i < 0 || j < 0) return -1;
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
                
                newCellNumber = cellNumber(i, y1, N);
                if (newCellNumber != -1) {
                    if (!oneOnly || (oneOnly && A[i][y1] == 1)) {
                        adjList[cellId].push_back(newCellNumber);
                        adjList[newCellNumber].push_back(cellId); 
                    }
                }
                
                newCellNumber = cellNumber(i, y2, N);
                if (newCellNumber != -1) {
                     if (!oneOnly || (oneOnly && A[i][y2] == 1)) {
                        adjList[cellId].push_back(newCellNumber);
                        adjList[newCellNumber].push_back(cellId);
                     }
                }
                
                newCellNumber = cellNumber(x1, j, N);
                if (newCellNumber != -1) {
                    if (!oneOnly || (oneOnly && A[x1][j] == 1)) {
                        adjList[cellId].push_back(newCellNumber);
                        adjList[newCellNumber].push_back(cellId);
                    }
                }
                
                newCellNumber = cellNumber(x2, j, N);
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
    
    
    void reduceGraph(vector<vector<int>>& adjList, map<int, vector<int>> connectedComponentMap) {
        map<int, int> vertexToFirstVertexMap; 
        for (int i = 0; i<2; i++) {
            int firstVertexOfIsland = connectedComponentMap[i][0];
            // Notice the reference we dont want a copy of adJListOfFirstVertex as we want to modify the graph
            vector<int> & adJListOfFirstVertex = adjList[firstVertexOfIsland];   
            set<int> ss;
            // Insrt all the elements of adJListOfFirstVertex in set ss. 
            ss.insert(adJListOfFirstVertex.begin(), adJListOfFirstVertex.end());  
            for (int j = 1;j < connectedComponentMap[i].size();j++){
                int vertexToMerge =  connectedComponentMap[i][j];
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
                if (vertexToFirstVertexMap.find(adjList[i][j]) != vertexToFirstVertexMap.end()) {
                    // Replace with firstVertex Of Connected Component
                    adjList[i][j] = vertexToFirstVertexMap[adjList[i][j]];   
                }
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        vector<vector<int>> adjList = createGraph(A, true);
        int N = A.size();
        vector<int> connectedComponents(N * N, 0);
        noOfConnectedComponents(adjList, connectedComponents);
        map<int, vector<int>> connectedComponentMap;
        for (int i = 0; i< A.size(); i++) {
            for (int j = 0; j< A[i].size();j++) {
                if (A[i][j] == 1) {
                    int cellId = cellNumber(i, j, N);
                    connectedComponentMap[connectedComponents[cellId]].push_back(cellId); 
                }
            }
        }
        
        adjList = createGraph(A, false);
        reduceGraph(adjList, connectedComponentMap);
        vector<int> distance = bfs(adjList, connectedComponents, connectedComponentMap[0][1], 1);
        int minDist = distance[0];
        for (int i = 1; i< distance.size(); i++) {
            minDist = min(minDist, distance[i]);
        }
        return minDist;
    }
};