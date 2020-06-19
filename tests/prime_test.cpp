#include "gtest/gtest.h"
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) {
  if (n < 2)
    return false;
  if (n == 2)
    return 2;

  int N = sqrt(n);
  // Implement this
  if (n % 2 == 0)
    return false;

  for (int i = 3; i <= N; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}
vector<int> sieve(int n) {
  vector<bool> prime(true);
  vector<int> prime_num;
  for (int i = 0; i <= n; i++) {
    prime[i] = isPrime(i);
    if(prime[i]){
        prime_num.push_back(i);
    }
  }
  return prime_num;
}

TEST(testIsPrime, basicTest) {
  EXPECT_EQ(false, isPrime(1));
  EXPECT_EQ(true, isPrime(2));
  EXPECT_EQ(true, isPrime(3));
  EXPECT_EQ(false, isPrime(4));
  EXPECT_EQ(true, isPrime(5));
  EXPECT_EQ(false, isPrime(6));
  EXPECT_EQ(true, isPrime(7));
  EXPECT_EQ(false, isPrime(8));
  EXPECT_EQ(false, isPrime(9));
  EXPECT_EQ(false, isPrime(10));
}
TEST(testSieve, emptyTest) {
  vector<int> expected{};
  vector<int> output = sieve(1);
  EXPECT_EQ(expected.size(), output.size());
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(expected[i], output[i]);
  }
}
TEST(testSieve, basicTest) {
  vector<int> expected{2};
  vector<int> output = sieve(2);
  EXPECT_EQ(expected.size(), output.size());
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(expected[i], output[i]);
  }
}
TEST(testSieve, basicTest2) {
  vector<int> expected{2, 3};
  vector<int> output = sieve(3);
  EXPECT_EQ(expected.size(), output.size());
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(expected[i], output[i]);
  }
}
TEST(testSieve, basicTest3) {
  vector<int> expected{2, 3, 5, 7, 11, 13};
  vector<int> output = sieve(15);
  EXPECT_EQ(expected.size(), output.size());
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(expected[i], output[i]);
  }
}