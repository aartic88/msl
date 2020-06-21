#include "sieve.hpp"

// Builder method to create a sieve object. Building the seive takes Theta(n) time and space
// TODO:: What more can you improve in the code.
Sieve Sieve::builder(int n)
{
    std::vector<bool> arr(n + 1, true); // Intial a vector of n+1 with true value. We start assuming every value is prime

    if (n >= 0)
    {
        arr[0] = false;
    }

    if (n >= 1)
    {
        arr[1] = false;
    }

    if (n >= 2)
    {
        arr[2] = true;
    }

    for (int i = 4; i <= n; i += 2)
    { // Make all even number false other than 2;
        arr[i] = false;
    }

    for (int i = 3; i <= n; i += 2)
    { // Iterate for i = 3,5,7,9...n
        if (arr[i] == true)
        { // If its a prime then we want to marks its multiple as non prime
            for (int j = i + i; j <= n; j += i)
            { // This loop will run very fast as initially
                // for smaller number it need to mark a lot as false, but for loarger number it has
                // to mark a very small number as false
                arr[j] = false;
            }
        }
    }
    return Sieve(arr);
}
// Sieve also provides a isPrime() method same as above but this runs in constant time
bool Sieve::isPrime(int n)
{
    return arr[n];
}
// Private constructor so client can not make an object directly
Sieve::Sieve()
{
}
Sieve::Sieve(std::vector<bool> &sieveArr)
{
    // We dont want to put calculation in the constructor so we are creating a private
    // constructor which will be called by our builder
    // TODO:: We need to copy the sieveArr to arr , This should be avoid, Need to learn more C++ to fix this.
    this->arr = sieveArr;
}