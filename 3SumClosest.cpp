#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[nums.size() - 1];
        for (int i = 0; i < nums.size(); ++i)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                {
                    return sum;
                }
                if (abs(target - sum) < abs(closestSum - target))
                {
                    /* let target = 1 for example , sum = 2 , closestSum= 3
                    1 - sum(2) = 1 , closestSum(3) - 1 = 2
                    */
                    closestSum = sum;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return closestSum;
    }
};