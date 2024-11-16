#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//! brute force lol
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    double median = 0;
    vector<int> result;
    result.reserve(nums1.size() + nums2.size()); // prevents multiple memory reallocations
    result = nums1;
    result.insert(result.end(), nums2.begin(), nums2.end());
    sort(result.begin(), result.end());

    if (result.size() % 2 != 0) // this is for arrays of odd size, return mid
    {
      median += result[result.size() / 2];
    }
    else
    {
      median += (result[(result.size() - 1) / 2] + result[result.size() / 2]) / 2.0;
    }
    return median;
  }
};