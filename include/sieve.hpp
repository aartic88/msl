#ifndef SIEVE_HPP_ // This is called C++ Header Inclusion Gaurd which must be included in every header
#define SIEVE_HPP_ // This ensure a cpp source file can include this content only once
#include <vector>
// You cannot use using namespace std; in a header file. This lead to namespace pollution
class Sieve
{
public:
    // Builder method to create a sieve object. Building the seive takes Theta(n) time and space
    static Sieve builder(int n);
    // Sieve also provides a isPrime() method same as above but this runs in constant time
    bool isPrime(int n);

private:
    Sieve(); // Private constructor so client can not make an object directly
    Sieve(std::vector<bool> &sieveArr);

    std::vector<bool> arr;
};
#endif // SIEVE_HPP_