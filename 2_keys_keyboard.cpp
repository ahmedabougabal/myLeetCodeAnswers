#include <iostream>
using namespace std;
//! method 1
class Solution_1
{
public:
  int minSteps(int n)
  {
    int factor = 2;
    int operations = 0;
    while (n > 1)
    {
      while (n % factor == 0)
      {
        operations += factor;
        n /= factor;
      }
      factor++;
    }
    return operations;
  }
};

//! method 2
class Solution_2
{
public:
  int minSteps(int n)
  {
    int operations = 0;
    for (int factor = 2; factor * factor <= n; ++factor)
    {
      while (n % factor == 0)
      {
        operations += factor;
        n /= factor;
      }
    }
    if (n > 1)
    {
      operations += n;
    }
    return operations;
  }
};
