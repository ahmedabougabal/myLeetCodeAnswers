#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> findPeaks(vector<int> &mountain)
  {
    vector<int> res;
    for (int i = 1; i < mountain.size() - 1; ++i)
    {
      if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
      {
        res.push_back(i);
      }
    }
    return res;
  }
};