#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> AdjList;

AdjList makeAdjList(vector<vector<int>> &prerequisites, int n)
{
    AdjList graphAL(n);
    for (auto it = prerequisites.begin(); it != prerequisites.end(); it++)
    {
        vector<int> v = *it;
        int e_second = v[1], e_first = v[0];
        graphAL[e_second].push_back(e_first);
    }
    return graphAL;
}

void DFS(AdjList &graphAL, int startingVertex, vector<bool> &visited, vector<int> &departingVertx, int &time)
{
    visited[startingVertex] = true;
    time++;
    //do for evert edge (startingVertex->v)
    for (int v : graphAL[startingVertex])
    {
        if (!visited[v])
        {
            DFS(graphAL, v, visited, departingVertx, time);
        }
    }
    departingVertx[time] = startingVertex;
    time++;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    AdjList graphAL = makeAdjList(prerequisites, numCourses);
    vector<bool> visited(numCourses);
    vector<int> departingVertx(2 * numCourses, -1);
    int time = 0;
    for (int i = 0; i < numCourses; i++)
    {
        if (visited[i] == false)
        {
            DFS(graphAL, i, visited, departingVertx, time);
        }
    }
    vector<int> departTime(numCourses);
    for (int i = 0; i < 2 * numCourses; i++)
    {
        if (departingVertx[i] != -1)
        {
            departTime[departingVertx[i]] = i;
        }
    }
    for (int u = 0; u < numCourses; u++)
    {
        for (int v : graphAL[u])
        {
            if (departTime[u] <= departTime[v])
                return {};
        }
    }

    vector<int> newdepartingVertx;
    for (int i = 2 * numCourses - 1; i >= 0; i--)
    {
        if (departingVertx[i] != -1)
            newdepartingVertx.push_back(departingVertx[i]);
    }

    return newdepartingVertx;
}

TEST(testGraph, basictopoSort)
{
    //vector<vector<int>> prereq1 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};  // 3210
    //vector<int> order1 = findOrder(4, prereq1);
    //for (int x : order1)
    //    cout << x << " ";
    //cout << endl;
    vector<vector<int>> prereq2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}}; // 0213
    vector<int> order2 = findOrder(4, prereq2);
    vector<int> output2 = {0, 2, 1, 3};
    EXPECT_EQ(order2, output2);

    vector<vector<int>> prereq3 = {{1, 0}};
    vector<int> order3 = findOrder(2, prereq3);
    for (int x : order3)
        cout << x << " ";
    cout << endl;
}

TEST(testGraph, Acyclicgraph)
{
    vector<vector<int>> prereq1 = {{1, 0}, {0, 1}};
    vector<int> order1 = findOrder(2, prereq1);
    vector<int> output1 = {};
    EXPECT_EQ(order1, output1);
}
