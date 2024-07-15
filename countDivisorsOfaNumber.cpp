#include <iostream>
#include <limits.h>
using namespace std;

int divisors(int n)
{
  int count = 1; // since all numbers are divisble by 1 :)
  for (int i = 1; i < n; i++)
  {
    if (n % i == 0)
    {
      count++;
    }
  }
  return count;
}
