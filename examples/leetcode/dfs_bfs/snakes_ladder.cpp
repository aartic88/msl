#include <gtest/gtest.h>
#include <vector>
#include <queue>
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
typedef pair<int,int> Edge;
typedef vector<Edge> EdgeList;
typedef vector<EdgeList> AdjList;
#define VISITED 1
#define UNVISITED 0

vector<int> convert2Dto1D(vector<vector<int>> &snakeLadderMatrix){
    int n = snakeLadderMatrix.size();
    for(int i=1; i<n;i+=2){
        if(n%2==0)
        reverse(snakeLadderMatrix[i].begin(),snakeLadderMatrix[i].end());
        else
        reverse(snakeLadderMatrix[i-1].begin(),snakeLadderMatrix[i-1].end());
    }
    vector<int> matrix1Dimage;
    for(int i=n-1;i>=0;i--)
        for(int j=n-1; j>=0;j--)
            matrix1Dimage.push_back(snakeLadderMatrix[i][j]);
    return matrix1Dimage;
}

AdjList makeAdjList(vector<vector<int>> &snakeLadderMatrix)
{
    int n = snakeLadderMatrix.size();
    AdjList graphAL(n*n);
    vector<int> matrix1DImage = convert2Dto1D(snakeLadderMatrix);
    
    Edge e;
    for(int i=0; i<n*n; i++){
        e.first=i+1;
        for(int j=i+1;j<=i+6 && j<n*n; j++){
            if(matrix1DImage[i]!=-1){
                e.second=matrix1DImage[i];
                graphAL[i].push_back(e);
                break;
            }
            else{
                if(matrix1DImage[j]==-1){
                    e.second=j+1;
                    graphAL[i].push_back(e);
                }
                else{
                    e.second=matrix1DImage[j];
                    graphAL[i].push_back(e);
                }
            }
        }
    }
    return graphAL;
}
vector<int> bfs (const AdjList & graph, int numVertex, int startingVertex) {
    // inside int main()---no recursion
    vector<int> distance(numVertex, INT32_MAX);
    distance[startingVertex] = 0;
    queue<int> q; 
    q.push(startingVertex+1);
    // distance from source s to s is 0
    // start from source
    while (!q.empty()) {
        int u = q.front(); q.pop();
        // queue: layer by layer!
        for (int j = 0; j < (int)graph[u-1].size(); j++) {
            Edge e = graph[u-1][j];
            // for each neighbor of u
            int otherVertex  = u == e.first ? e.second : e.first;
            if (distance[otherVertex-1] == INT32_MAX) {
                // if v.first is unvisited + reachable
                distance[otherVertex-1] = distance[u-1] + 1;
                // make d[v.first] != INF to flag it
                q.push(otherVertex);
                // enqueue v.first for the next iteration
            }
        }
    }
    return distance;
}
TEST(testGraph, basicShortestPath0)
{
    vector<vector<int>> snakeLadderMatrix = {{-1, -1, -1, -1, },
                                             {5, -1, -1, -1, },
                                             {-1, -1, 15, -1, },
                                             {-1, 11, -1, -1, }};
    AdjList graphAL = makeAdjList(snakeLadderMatrix);
    auto distance = bfs(graphAL, 16, 0);
    for (int i = 0; i<distance.size(); i++) {
        cout << i <<" " << distance[i] << endl;
    }

} 
TEST(testGraph, basicShortestPath1)
{
    vector<vector<int>> snakeLadderMatrix = {{-1, -1, -1, -1, -1, -1},
                                             {-1, -1, -1, -1, -1, -1},
                                             {-1, -1, -1, -1, -1, -1},
                                             {-1, 35, -1, -1, 13, -1},
                                             {-1, -1, -1, -1, -1, -1},
                                             {-1, 15, -1, -1, -1, -1}};
    AdjList graphAL = makeAdjList(snakeLadderMatrix);
    auto distance = bfs(graphAL, 36, 0);
    for (int i = 0; i<distance.size(); i++) {
        cout << i <<" " << distance[i] << endl;
    }
}
TEST(testGraph, basicShortestPath2)
{
    vector<vector<int>> snakeLadderMatrix = {
        {-1, -1},
        {-1, 3},
    };
    AdjList graphAL = makeAdjList(snakeLadderMatrix);
    auto distance = bfs(graphAL, 4, 0);
    for (int i = 0; i<distance.size(); i++) {
        cout << i <<" " << distance[i] << endl;
    }
}
TEST(testGraph, basicShortestPath3)
{
    vector<vector<int>> snakeLadderMatrix = {{4, -1, -1},
                                             {-1, -1, -1},
                                             {-1, 8, -1}};
    AdjList graphAL = makeAdjList(snakeLadderMatrix);
    auto distance = bfs(graphAL, 9, 0);
    for (int i = 0; i<distance.size(); i++) {
        cout << i <<" " << distance[i] << endl;
    }
}