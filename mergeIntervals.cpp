#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  // vector<int> flat_vec(vector<vector<int>> &bulk_vec)
  // {
  //   vector<int> result;
  //   for (auto const &inner : bulk_vec)
  //   {
  //     for (auto const &element : inner)
  //     {
  //       result.push_back(element);
  //     }
  //   }
  //   return result;
  // }
  vector<vector<int>> refine(vector<vector<int>> &vec)
  {
    vector<vector<int>> refined;
    for (int i = 1; i < vec.size(); ++i)
    {
      if (vec[i - 1][1] >= vec[i][0])
      {
        vec[i][0] = min(vec[i - 1][0], vec[i][0]);
        vec[i][1] = max(vec[i][1], vec[i - 1][1]);
        vec[i - 1] = {-1, -1};
      }
    }
    for (const auto &i : vec)
    {
      if (i[0] != -1)
      {
        refined.push_back(i);
      }
    }
    return refined;
  }
  bool isSorted(vector<vector<int>> &vec)
  {
    for (int i = 1; i < vec.size(); ++i)
    {
      if (vec[i][0] < vec[i - 1][0])
      {
        return false;
      }
    }
    return true;
  }
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    if (intervals.empty())
    {
      return {};
    }
    if (!isSorted(intervals))
    {
      sort(intervals.begin(), intervals.end());
    }
    return refine(intervals);
  }
};
