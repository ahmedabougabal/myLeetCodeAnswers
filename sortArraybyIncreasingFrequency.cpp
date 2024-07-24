#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// i will be using C++ comparator (LAMBDA FUNCTION) & unordered map to tackle this

class Solution
{
public:
  vector<int> frequencySort(vector<int> &nums)
  {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
      umap[nums[i]]++;
    }
    //! Step 2: Sort based on frequency and value
    sort(nums.begin(), nums.end(), [&](int a, int b)
         {
  //* If frequencies are equal, sort in descending order
      if(umap[a] == umap[b]){ 
        return a > b;
      }
//! frequencies not equal? return values sorted ascendingly according to their frequencies 
      return umap[a] < umap[b]; });
    return nums;
  }
};
