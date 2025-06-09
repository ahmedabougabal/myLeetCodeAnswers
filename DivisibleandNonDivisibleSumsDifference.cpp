#include <iostream>
using namespace std;

class Solution
{
public:
  int differenceOfSums(int n, int m)
  {
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i <= n; ++i)
    {
      num1 += i;
    }
    for (int i = 0; i <= m; ++i)
    {
      num2 += i;
    }
  }
};
