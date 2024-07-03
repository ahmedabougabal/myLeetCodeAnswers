#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> result;
    sort(nums1.begin(), nums1.end());
    for (int i = 0; i < nums1.size(); i++)
    {
      for (int j = 0; j < nums2.size(); j++)
      {
        if (nums1[i] == nums2[j])
        {
          result.push_back(nums2[j]);     // if a match is found, push it to the vector result
          nums2.erase(nums2.begin() + j); // erases the pushed element
          break;
        }
      }
    }
    return result;
  }
};