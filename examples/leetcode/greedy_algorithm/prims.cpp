#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

class bidirectional_map {
  private:
    multimap<int, int>  cost_vertex_map; // cost (non unique) -> vertexId
    typedef multimap<int, int>::const_iterator value_multmap_iterator;  // typedef so that I can use the type in map
    map<int, value_multmap_iterator> vertex_cost_map;
    typedef map<int, value_multmap_iterator>::iterator bidirectional_map_iterator;
  public:
    bidirectional_map_iterator find(int id) {
        return vertex_cost_map.find(id);
    }

    bidirectional_map_iterator end() {
        return vertex_cost_map.end();
    }

    void insert(int key, int value) {
        auto it = cost_vertex_map.insert(std::make_pair(value, key));
        vertex_cost_map.insert(make_pair(key, it));
    }

    void update(int key, int value) {
        value_multmap_iterator it = vertex_cost_map[key];
        cost_vertex_map.erase(it);
        auto it2 = cost_vertex_map.insert(std::make_pair(value, key));
        vertex_cost_map[key] = it2;
    }

    // Return key, value pair with the min value
    pair<int, int> get_min() {
      auto it = cost_vertex_map.begin();
      return make_pair(it->second, it->first);
    }

    void remove(int key) {
      auto it = vertex_cost_map[key];
      cost_vertex_map.erase(it);
      vertex_cost_map.erase(key);
    }

    bool empty() {
      return cost_vertex_map.empty();
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

// https://en.wikipedia.org/wiki/Prim%27s_algorithm
int prims_algorithm(vector<vector<int>> weightedMatrix) {
  int sum = 0;
  int size = weightedMatrix.size();
  
  bidirectional_map cost;
  vector<pair<int,int>> edge_cheapest;
  set<int> forest;   // Included in minimum spanning tree
  for (int i = 0; i < size; i++) { // inserting egdes adjacent to startingPoint
    cost.insert(i, INT32_MAX); // Set to +Inf
    edge_cheapest.push_back(make_pair(-1,-1));  // set to special flag .. the edge providing that cheapest connection
  }
  while (!cost.empty()) {
    auto vertex = cost.get_min().first;
    cost.remove(vertex);
    forest.insert(vertex);
    if (edge_cheapest[vertex].first != -1) {
      forest.insert(edge_cheapest[vertex].first);
      forest.insert(edge_cheapest[vertex].second);
    }

    for (int i = 0; i < size; i++) {
      if (weightedMatrix[vertex][i] != 0) {
          auto it = cost.find(i);
          if (it != cost.end()){
            int cost_fnd = it->second->first;
            if (weightedMatrix[vertex][i] < cost_fnd) {
              cost.update(i, weightedMatrix[vertex][i]);
              edge_cheapest[i] = make_pair(vertex, i);
            }
          }
      }
    }
  }
  for (int i = 0;i< size; i++) {
    if (edge_cheapest[i].first != -1)
    sum += weightedMatrix[edge_cheapest[i].first][edge_cheapest[i].second];
  }
  return sum;
}

TEST(testGraph, basicshortestPath) { // Edge {u,v,weight}
  vector<vector<int>> prereq1 = {{0, 1, 1}, {0, 2, 3},  {0, 3, 11}, {1, 4, 9},
                                 {1, 5, 8}, {1, 2, 2},  {2, 5, 7},  {2, 3, 13},
                                 {2, 6, 5}, {3, 7, 10}, {6, 7, 4},  {5, 6, 6},
                                 {4, 5, 12}};
  vector<vector<int>> weightedMatrix = makeWeightedMatrix(prereq1, 9);
  int sum = prims_algorithm(weightedMatrix);
  EXPECT_EQ(sum, 37);
}

TEST(testGraph, basicshortestPath2) { // Edge {u,v,weight}
   vector<vector<int>> prereq1 = {{0, 1, 4},  {0, 7, 6},  {1, 2, 8}, {1, 7,
     11}, {2, 3, 7},  {2, 8, 3},  {2, 5, 4}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10},
     {5, 6, 2}, {6, 8, 6}, {6, 7, 1},  {7, 8, 7}};
  vector<vector<int>> weightedMatrix = makeWeightedMatrix(prereq1, 9);
  int sum = prims_algorithm(weightedMatrix);
  EXPECT_EQ(sum,36);
}
