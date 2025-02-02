#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isArraySpecial(vector<int> &nums)
  {
    bool res;
    for (int i = 1; i < nums.size(); ++i)
    {
      if (nums[i - 1] % 2 == nums[i] % 2)
      {
        res = false;
        break;
      }
      res = true;
    }
    return res;
  }
};
