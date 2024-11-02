#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
  //* Implememting the most effeccient solution for calculating the primes count
  // using the Sieve Sieve of Eratosthenes
public:
  int countPrimes(int n)
  {
    int count = 0;
    vector<bool> isPrime(n, true);
    for (int i = 2; i <= sqrt(n); ++i)
    {
      // coreLogic: if the number i is a prime, then surely its multiples arenot primes
      if (isPrime[i])
      {
        for (int j = i * i; j < n; j += i)
        {
          isPrime[j] = false;
        }
      }
    }
    for (int i = 2; i < n; ++i)
    {
      if (isPrime[i])
      {
        count += 1;
      }
    }
    return count;
  }
};

int main()
{
  Solution sol;
  cout << sol.countPrimes(10);
  return 0;
}