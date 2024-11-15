#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    int minSub = 1;
    int maxSub = 1;
    sort(nums.begin(), nums.end());
    if (nums.size() == 0)
    {
      return 0;
    }
    if (nums.size() == 1)
    {
      return 1;
    }
    for (int i = 1; i < nums.size(); ++i)
    {
      if (nums[i] == nums[i - 1])
      {
        continue;
      }
      else if (i <= nums.size() && nums[i] == nums[i - 1] + 1)
      {
        minSub++;
        maxSub = max(maxSub, minSub);
      }
      else
      {
        minSub = 1;
      }
    }
    return maxSub;
  }
};

int main()
{
  Solution sol;
  vector<int> v = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}; // should be 9 not 6
  cout << sol.longestConsecutive(v);
  return 0;
}

// example : 1,  2,  3,  4  , 100,  200 --> 4 substrings