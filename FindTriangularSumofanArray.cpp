#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int result = 0;
        vector<vector<int>> dp;
        if (nums.size() == 1)
        {
            result = nums[0];
            return result;
        }
        dp.push_back(nums);

        for (int i = 0; i < nums.size(); ++i)
        {
            vector<int> newRow;
            for (int j = 0; j < dp[i].size() - 1; ++j)
            {
                newRow.push_back((dp[i][j] + dp[i][j + 1]) % 10);
            }
            dp.push_back(newRow);
        }
        return dp[nums.size() - 1][0];
    }
};