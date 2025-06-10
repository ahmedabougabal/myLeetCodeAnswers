#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int differenceOfSums(int n, int m)
  {
    int num1 = 0;
    int num2 = 0;
    vector<int> vec1;
    vector<int> vec2;
    for (int i = 0; i <= n; ++i)
    {
      if (i % m != 0)
      {
        vec1.push_back(i);
      }
    }

    for (int i = 0; i <= n; ++i)
    {
      if (i % m == 0)
      {
        vec2.push_back(i);
      }
    }

    for (auto i : vec1)
    {
      num1 += i;
    }
    for (auto i : vec2)
    {
      num2 += i;
    }

    return num1 - num2;
  }
};
