#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int rangeSum(vector<int> &nums, int n, int left, int right)
  {
    n = nums.size();
    const int mod = 1000000007;
    vector<int> vec;
    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
      int currentSum = 0;
      for (int j = i; j < n; ++j)
      {
        currentSum += nums[j];
        vec.push_back(currentSum);
      }
    }
    sort(vec.begin(), vec.end());
    for (int i = left - 1; i < right; ++i)
    {
      sum = (sum + vec[i]) % mod;
    }
    return sum;
  }
};
int main()
{
  vector<int> vec = {1, 2, 3, 4};
  Solution sol;
  cout << sol.rangeSum(vec, vec.size(), 1, 5) << endl;
  return 0;
}