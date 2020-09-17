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

const int dr[] = {1,1,0,-1,-1,-1, 0, 1};
const int dc[] = {0,1,1, 1, 0,-1,-1,-1};

void dfs (const AdjacencyList & graph, vector<int> & visited, int startingVertex) {
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

vector<int> bfs (const AdjacencyList & graph, int numVertex, int startingVertex) {
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

void dfs2 (const AdjacencyList & graph, vector<int> & connectedComponents, int startingVertex, int componentCount) {
    connectedComponents[startingVertex] = componentCount;
    // important: we mark this vertex as visited
    for (int j = 0; j < (int)graph[startingVertex].size(); j++) { // default DS: AdjList
        Edge e = graph[startingVertex][j];
        // v is a (neighbor, weight) pair
        int otherVertex  = startingVertex == e.first ? e.second : e.first;
        if (connectedComponents[otherVertex] == 0) {
        // important check to avoid cycle
            dfs2(graph, connectedComponents, otherVertex, componentCount); // recursively visits unvisited neighbors of vertex u
        }
    }
}

vector<int> connected_component (const AdjacencyList & graph) {
    // important: we mark this vertex as visited
    vector<int> connectedComponents(graph.size(), 0);
    int componentCount = 1;
    for (int j = 0; j < (int)graph.size(); j++) { // default DS: AdjList
        if (connectedComponents[j] == 0) {
            dfs2(graph, connectedComponents, j, componentCount++);
        }
    }
    return connectedComponents;
}


TEST(testGraph, basicConnectedComponentTest)
{
    EdgeList graphEL = {{1,2},{2,4},{1,3},{2,5},{3,5}, {4,5}, {5,6}, {8, 9}, {9,10}, {10,11}};
    AdjacencyList graphAL = convertEdgeListToAdjacencyList(graphEL);
    auto connectedComponents = connected_component(graphAL);
    for (int i = 0; i<connectedComponents.size(); i++) {
        cout << i <<" " << connectedComponents[i] << endl;
    }
}


// trick to explore an implicit 2D grid
// S,SE,E,NE,N,NW,W,SW neighbors
int floodfill(vector<vector<int>> & grid, int r, int c, char c1, char c2) {
// returns the size of CC
int R = grid.size();
int C = R > 0 ? grid[0].size(): 0;  //Column size

if (r < 0 || r >= R || c < 0 || c >= C) return 0;
// outside grid
if (grid[r][c] != c1) return 0;
// does not have color c1
int ans = 1;
// adds 1 to ans because vertex (r, c) has c1 as its color
grid[r][c] = c2;
// now recolors vertex (r, c) to c2 to avoid cycling!
for (int d = 0; d < 8; d++) {
    ans += floodfill(grid, r + dr[d], c + dc[d], c1, c2);
}
return ans;
// the code is neat due to dr[] and dc[]
}

TEST(testGraph, basicFloodFillOn2DGridTest)
{
    vector<vector<int>>  image {{0,0,0,0,0,0,0,0,0,0},
                                {0,1,1,1,1,1,1,0,0,0},
                                {0,1,0,0,0,0,1,0,0,0},
                                {0,1,0,0,0,0,1,0,0,0},
                                {0,1,0,0,0,0,1,0,0,0},
                                {0,1,1,1,0,1,1,0,0,0},
                                {0,0,0,1,0,1,0,0,0,0},
                                {0,0,0,1,0,1,0,0,0,0},
                                {0,0,0,1,1,1,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0}};

    floodfill(image, 3, 3, 0, 2);

    for (int i = 0;i<image.size();i++) {
        for (int j =0; j<image[i].size();j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

}


void dfs3 (const AdjacencyList & graph, vector<int> & visited, int startingVertex, vector<int> & ts) {
    visited[startingVertex] = VISITED;
    // important: we mark this vertex as visited
    for (int j = 0; j < (int)graph[startingVertex].size(); j++) { // default DS: AdjList
        Edge e = graph[startingVertex][j];
        // v is a (neighbor, weight) pair
        int otherVertex  = startingVertex == e.first ? e.second : e.first;
        if (visited[otherVertex] == UNVISITED) {
        // important check to avoid cycle
            dfs3(graph, visited, otherVertex, ts); // recursively visits unvisited neighbors of vertex u
           
        }
    }
    ts.push_back(startingVertex);
}

vector<int> topological_sort(const AdjacencyList & graph, int startingVertex) {
    vector<int> ts;
    vector<int> visited(graph.size(), UNVISITED); // max + 1
    // global vector to store the toposort in reverse order
    dfs3(graph, visited, startingVertex, ts);    
    return ts;
}

TEST(testGraph, basicTopoSortTest)
{
    EdgeList graphEL = {{1,2},{2,4},{1,3},{2,5},{3,5}, {4,5}, {5,6}};
    AdjacencyList graphAL = convertEdgeListToAdjacencyList(graphEL, false);
    auto connectedComponents = topological_sort(graphAL, 1);
    for (int i = 0; i<connectedComponents.size(); i++) {
        cout << i <<" " << connectedComponents[i] << endl;
    }
}
