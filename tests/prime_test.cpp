#include <gtest/gtest.h>
#include <cmath>
#include <vector>

#include "sieve.hpp"
#include "msl_math.hpp"
using namespace std;

TEST(testIsPrime, basicTest)
{
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
// The following tests ensures that for small
// values it works properly and there are not segment faults
TEST(testSieve, emptyTest)
{
  Sieve s = Sieve::builder(0);
  EXPECT_EQ(false, s.isPrime(0));
}

TEST(testSieve, boundaryCaseTest)
{
  Sieve s = Sieve::builder(1);
  EXPECT_EQ(false, s.isPrime(1));
}

TEST(testSieve, boundaryCaseTest2)
{
  Sieve s = Sieve::builder(2);
  EXPECT_EQ(true, s.isPrime(2));
}

// These tests bellow checks the function works correctly
// This is same as testIsPrime::basicTest this one works faster
TEST(testSieve, basicTest)
{
  Sieve s = Sieve::builder(10);
  EXPECT_EQ(false, s.isPrime(1));
  EXPECT_EQ(true, s.isPrime(2));
  EXPECT_EQ(true, s.isPrime(3));
  EXPECT_EQ(false, s.isPrime(4));
  EXPECT_EQ(true, s.isPrime(5));
  EXPECT_EQ(false, s.isPrime(6));
  EXPECT_EQ(true, s.isPrime(7));
  EXPECT_EQ(false, s.isPrime(8));
  EXPECT_EQ(false, s.isPrime(9));
  EXPECT_EQ(false, s.isPrime(10));
}

TEST(testSieve, basicTest2)
{
  Sieve s = Sieve::builder(20);
  EXPECT_EQ(true, s.isPrime(11));
  EXPECT_EQ(false, s.isPrime(12));
  EXPECT_EQ(true, s.isPrime(13));
  EXPECT_EQ(false, s.isPrime(14));
  EXPECT_EQ(false, s.isPrime(15));
  EXPECT_EQ(false, s.isPrime(16));
  EXPECT_EQ(true, s.isPrime(17));
  EXPECT_EQ(false, s.isPrime(18));
  EXPECT_EQ(true, s.isPrime(19));
  EXPECT_EQ(false, s.isPrime(20));
}
