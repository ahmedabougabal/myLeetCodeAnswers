#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void generateTriplets(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                {
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
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
    }

    int threeSumClosest(vector<int> &nums, int target)
    {
    }
};