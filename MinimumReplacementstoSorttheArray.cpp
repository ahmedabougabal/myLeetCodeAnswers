#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  long long minimumReplacement(vector<int> &nums)
  {
    long long operations = 0; // return the number of min operations required
    int n = nums.size();
    // leetcode hint 1  : not optimal to do operations on the last element so that is why we started from the second last element
    for (int i = n - 2; i >= 0; --i)
    {
      //* nums[i+1] is the next number
      if (nums[i] > nums[i + 1])
      {
        int parts = (nums[i] + nums[i + 1] - 1) / nums[i + 1]; //! ceiling division
        operations += parts - 1;
        nums[i] /= parts;
      }
    }
    return operations;
  }
};
