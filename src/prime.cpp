#include <cmath>
// This runs in Theta (n^.5)
bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2)
    {
        return 2;
    }

    int N = sqrt(n);
    // Implement this
    if (n % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i <= N; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}