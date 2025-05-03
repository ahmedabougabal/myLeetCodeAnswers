#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int vector_size = nums.size();
        int index = vector_size - k;
        return nums[index];
    }
};