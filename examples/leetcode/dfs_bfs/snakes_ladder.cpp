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

typedef vector<vector<int>> AdjList;

AdjList makeAdjList(vector<vector<int>> &snakeLadderMatrix)
{
    int n = snakeLadderMatrix.size();
    AdjList graphAL(n * n);
    for (int i = 0; i < n * n; i++)
    {
            graphAL[i].push_back(i + 1);
    }
    int count = n * n;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < snakeLadderMatrix[i].size(); j++)
        {
            if (flag)
                count--;
            else
                count++;
            if (snakeLadderMatrix[i][j] != -1)
            {
                graphAL[count].push_back(snakeLadderMatrix[i][j]);
            }
        }
        flag = !flag;
        count = count - n;
        if (!flag)
            count--;
        else
            count++;   //addition of unsigned offset overflow.......
    }
    return graphAL;
}
int bfs (const AdjList & graph, int numVertex, int startingVertex) {
    // inside int main()---no recursion
    vector<int> distance(numVertex, INT32_MAX);
    distance[startingVertex] = 0;
    queue<int> q; 
    q.push(startingVertex);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        for (int j = 0; j < (int)graph[u].size(); j++) {
            int e = graph[u][j];
            // for each neighbor of u
            if (distance[e] == INT32_MAX) {
                // if v.first is unvisited + reachable
                distance[e] = distance[u] + 1;
                // make d[v.first] != INF to flag it
                q.push(e);
                // enqueue v.first for the next iteration
            }
        }
    }
    return distance[numVertex-1];
}

TEST(testGraph, basicShortestPath)
{
    vector<vector<int>> snakeLadderMatrix = {{-1, -1, -1, -1, -1, -1},
                                             {-1, -1, -1, -1, -1, -1},
                                             {-1, -1, -1, -1, -1, -1},
                                             {-1, 35, -1, -1, 13, -1},
                                             {-1, -1, -1, -1, -1, -1},
                                             {-1, 15, -1, -1, -1, -1}};
    AdjList graphAL = makeAdjList(snakeLadderMatrix);
    auto distance = bfs(graphAL,36,1);
    cout<<distance<<endl;
}
TEST(testGraph, basicShortestPath2)
{
    vector<vector<int>> snakeLadderMatrix = {
        {-1, -1},
        {-1, 3},
    };
    AdjList graphAL = makeAdjList(snakeLadderMatrix);
    auto distance = bfs(graphAL,4,1);
    cout<<distance<<endl;
}

