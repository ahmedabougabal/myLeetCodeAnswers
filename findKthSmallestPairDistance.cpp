#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
  int smallestDistancePair(vector<int> &nums, int k)
  {
    vector<int> distances;
    sort(nums.begin(), nums.end());
    for (auto i = 0; i < nums.size(); ++i)
    {
      for (auto j = i + 1; j < nums.size(); ++j)
      {
        distances.push_back(abs(nums[j] - nums[i]));
      }
    }
    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    return distances[k - 1];
  }
};
// The std::nth_element function is a useful method for finding the nth smallest (or largest) element in a range without fully sorting the entire range