#include <gtest/gtest.h>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef pair<int, int> Edge;
typedef vector<Edge> EdgeList;
typedef vector<EdgeList> AdjacencyList;
#define VISITED 1
#define UNVISITED 0

void dfs (AdjacencyList graph, vector<int> visited, int startingVertex) {
    visited[startingVertex] = VISITED;
    // important: we mark this vertex as visited
    for (int j = 0; j < (int)graph[startingVertex].size(); j++) { // default DS: AdjList
        Edge e = graph[startingVertex][j];
        // v is a (neighbor, weight) pair
        int otherVertex  = startingVertex == e.first ? e.second : e.first;
        if (visited[otherVertex] == UNVISITED) {
        // important check to avoid cycle
            dfs(graph, visited, otherVertex); // recursively visits unvisited neighbors of vertex u
            cout << "Edge " <<e.first << ", " << e.second << endl;
        }
    }
}

vector<int> bfs (AdjacencyList graph,int numVertex, int startingVertex) {
    // inside int main()---no recursion
    vector<int> distance(numVertex, INT32_MAX);
    distance[startingVertex] = 0;
    queue<int> q; 
    q.push(startingVertex);
    // distance from source s to s is 0
    // start from source
    while (!q.empty()) {
        int u = q.front(); q.pop();
        // queue: layer by layer!
        for (int j = 0; j < (int)graph[u].size(); j++) {
            Edge e = graph[u][j];
            // for each neighbor of u
            int otherVertex  = u == e.first ? e.second : e.first;
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

AdjacencyList convertEdgeListToAdjacencyList(const EdgeList& edgeList, bool undirected = true) {
    AdjacencyList graphAL;
    for (auto it = edgeList.begin(); it!= edgeList.end();it++) {
        Edge e = *it;
        int u = e.first;
        int v = e.second;
        // Resize/expand if required
        int x = max(u,v) + 1;
        if (graphAL.size() < x) {
            graphAL.resize(x); 
        }
        graphAL[u].push_back(e); // directed
        if (undirected) {
            graphAL[v].push_back(e); // undirected 
        }
    }

    return graphAL;
}



TEST(testGraph, basicDFSTest)
{
    EdgeList graphEL = {{1,2},{2,4},{1,3},{2,5},{3,5}, {4,5}, {5,6}};
    AdjacencyList graphAL = convertEdgeListToAdjacencyList(graphEL);
    vector<int> visited(7, UNVISITED); // max + 1
    dfs(graphAL, visited, 1 );
}

TEST(testGraph, basicBFSTest)
{
    EdgeList graphEL = {{1,2},{2,4},{1,3},{2,5},{3,5}, {4,5}, {5,6}};
    AdjacencyList graphAL = convertEdgeListToAdjacencyList(graphEL);
    auto distance = bfs(graphAL, 7 , 1);
    for (int i = 0; i<distance.size(); i++) {
        cout << i <<" " << distance[i] << endl;
    }

}

