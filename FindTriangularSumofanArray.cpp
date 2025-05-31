#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        vector<int> newNums(nums.size() - 1);
        int i = 0;
        while (i < nums.size() - 1)
        {
            newNums[i] = (nums[i] + nums[i + 1]) % 10;
            i++;
        }
        nums = newNums;
        return triangularSum(nums);
    }
};