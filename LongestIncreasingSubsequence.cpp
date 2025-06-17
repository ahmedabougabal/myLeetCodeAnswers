#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size());
        if (nums.size() == 1)
        {
            return 1;
        }
        if (adjacent_find(nums.begin(), nums.end(), not_equal_to<>()) == nums.end())
        {
            return 1;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            dp[i] = 1; // this is the base case before every if condition comparison between the current element at i and any previous number if any to see if it the nums at j can extent to nums at i or not
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 5, 3, 7};
    cout << sol.lengthOfLIS(nums); // 3 as of the array : [2,5,7]
    return 0;
}
