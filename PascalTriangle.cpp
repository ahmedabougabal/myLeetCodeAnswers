#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> dp;
        if (numRows >= 1)
        {
            dp.push_back({1});
        }
        if (numRows >= 2)
        {
            dp.push_back({1, 1});
        }
        for (int i = 2; i < numRows; ++i)
        {
            vector<int> newRow;
            newRow.push_back(1);

            for (int j = 0; j < i - 1; ++j)
            {
                newRow.push_back(dp[i - 1][j] + dp[i - 1][j + 1]);
            }

            newRow.push_back(1);
            dp.push_back(newRow);
        }
        return dp;
    }
};