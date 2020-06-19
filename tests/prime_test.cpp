#include "gtest/gtest.h"
#include <cmath>
#include <vector>
using namespace std;

// This runs in Theta (n^.5)
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

class Sieve {
  public: 
  // Builder method to create a sieve object. Building the seive takes Theta(n) time and space
  static Sieve builder (int n) {  
      vector<bool> arr(n+1, true);  // Intial a vector of n+1 with true value. We start assuming every value is prime

      if (n >=0) {
        arr[0] = false;
      }

      if (n >=1) {
        arr[1] = false;
      }
      
      if (n >=1) {
        arr[2] = true;
      }
      
      for (int i = 4; i <= n; i+=2) { // Make all even number false other than 2;
          arr[i] = false;
      }

      for (int i = 3; i <= n; i+=2) { // Iterate for i = 3,5,7,9...n
          if (arr[i] == true) { // If its a prime then we want to marks its multiple as non prime
              for (int j = i + i; j<=n; j += i) {  // This loop will run very fast as initially
              // for smaller number it need to mark a lot as false, but for loarger number it has 
              // to mark a very small number as false
                arr[j] = false;
              }
          }
      }
      return Sieve(arr);
  }
  // Sieve also provides a isPrime() method same as above but this runs in constant time
  bool isPrime(int n) {
    return arr[n];
  }

  private:
    Sieve() {} // Private constructor so client can not make an object directly
    Sieve(vector<bool> & sieveArr) {  
      // We dont want to put calculation in the constructor so we are creating a private 
      // constructor which will be called by our builder
      this->arr = sieveArr;
    }
    vector<bool> arr; 

};

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
// The following tests ensures that for small 
// values it works properly and there are not segment faults
TEST(testSieve, emptyTest) {
  Sieve s = Sieve::builder(0);
  EXPECT_EQ(false, s.isPrime(0));
}

TEST(testSieve, boundaryCaseTest) {
  Sieve s = Sieve::builder(1);
  EXPECT_EQ(false, s.isPrime(1));
}

TEST(testSieve, boundaryCaseTest2) {
  Sieve s = Sieve::builder(2);
  EXPECT_EQ(true, s.isPrime(2));
}

// These tests bellow checks the function works correctly
// This is same as testIsPrime::basicTest this one works faster
TEST(testSieve, basicTest) {
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

TEST(testSieve, basicTest2) {
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
