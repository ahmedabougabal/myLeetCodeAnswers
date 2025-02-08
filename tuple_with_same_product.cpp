#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int tupleSameProduct(vector<int> &nums)
  {
    unordered_map<int, vector<pair<int, int>>> map;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      for (int j = i + 1; j < nums.size(); ++j)
      {
        int product = nums[i] * nums[j];
        map[product].emplace_back(nums[i], nums[j]);
      }
    }
    //! commented lines are for debugging
    // int i = 0;
    for (auto &entry : map)
    {
      // cout << "product " << i << ": " << entry.first << " : ";
      // i++;
      int k = entry.second.size();
      // for (const auto pair : entry.second)
      // {
      //   cout << "pairs: (" << pair.first << ", " << pair.second << ")" << endl;
      // }
      count += (k * (k - 1) / 2);
    }
    return 8 * count;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 6, 3, 4}; // 8
  cout << "answer = " << sol.tupleSameProduct(nums) << endl;
  return 0;
}