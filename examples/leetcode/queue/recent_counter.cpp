#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class RecentCounter {
public:
  RecentCounter() {}
  std::queue<int> q;
  int ping(int t) {

    q.push(t); // At time t only [(t-3000)->t] will remain in the queue
    while (q.front() < (t - 3000))
      q.pop();
    return q.size();
  }
};

TEST(testRecentCounter, basicTest) {

  RecentCounter arr;
  std::cout << " "<<arr.ping(1);
  std::cout << " " <<arr.ping(100);
  std::cout << " " <<arr.ping(3001);
  std::cout << " " <<arr.ping(3002);

}
