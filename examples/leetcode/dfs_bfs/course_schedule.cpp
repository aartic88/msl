#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;
/* bool canFinish(int n, vector<vector<int>> &prerequisites){
    vector<vector<int>> G(n);
    int time = 0;
    vector<int> degree(n, 0), bfs;
        for (auto &e : prerequisites){
        int e_second = e[1], e_first = e[0];
        G[e_second].push_back(e_first);
        degree[e_first]++;
    }
    for (int i = 0; i < n; ++i){
        if (!degree[i]){
            bfs.push_back(i); //add vertices with degree=0
        }
    }
    for (int i = 0; i < bfs.size(); ++i)
        for (int j : G[bfs[i]]){
            if (--degree[j] == 0){
                bfs.push_back(j);
            }
        }
    return bfs.size() == n;
}
*/

typedef pair<int, int> Edge;
typedef vector<Edge> EdgeList;
typedef vector<vector<int>> AdjList;

AdjList makeAdjList(vector<vector<int>> &prerequisites, int n)
{
    AdjList graphAL(n);
    for (auto &e : prerequisites)
    {
        int e_second = e[1], e_first = e[0];
        graphAL[e_first].push_back(e_second);
    }
    return graphAL;
}

void DFS(AdjList &graphAL, int startingVertex, vector<bool> &visited, vector<int> &departure, int &time)
{
    visited[startingVertex] = true;
    //do for evert edge (startingVertex->v)
    for (int v : graphAL[startingVertex])
    {
        if (!visited[v])
        {
            DFS(graphAL, v, visited, departure, time);
        }
    }
    departure[startingVertex] = time++;
}

bool canFinish(int n, vector<vector<int>> &prerequisites)
{
    //empty case
    if (prerequisites.empty())
        return true;

    AdjList graphAL = makeAdjList(prerequisites, n);
    vector<bool> visited(n);
    vector<int> departure(n);
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            DFS(graphAL, i, visited, departure, time);
        }
    }
    //check graph is DAG---- (u,v) form back-edge
    for (int u = 0; u < n; u++)
    {
        for (int v : graphAL[u])
        {
            if (departure[u] <= departure[v])
                return false;
        }
    }
    return true;
}

TEST(testGraph, basicIsAcyclic)
{
    vector<vector<int>> prereq1 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    cout << "result = " << canFinish(4, prereq1) << endl;
    vector<vector<int>> prereq3 = {{1, 2}, {2, 4}, {3, 1}, {2, 5}, {5, 3}, {4, 5}, {5, 6}};
    cout << "result = " << canFinish(7, prereq3) << endl;
}
TEST(testGraph, emptyIsAcyclic)
{
    vector<vector<int>> prereq1 = {};
    cout << "result = " << canFinish(1, prereq1) << endl;
    vector<vector<int>> prereq3 = {};
    cout << "result = " << canFinish(2, prereq3) << endl;
}
TEST(testGraph, isolatedVexIsAcyclic)
{
    vector<vector<int>> prereq1 = {{1, 0}};
    cout << "result = " << canFinish(3, prereq1) << endl;
}