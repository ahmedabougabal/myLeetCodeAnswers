#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dps(vector<int> &nums, int l, int r, vector<vector<int>> &result)
    {
        r = nums.size() - 1;
        if (l == r)
        {
            result.push_back(nums);
            return;
        }
        for (int i = l; i <= r; ++i)
        {
            int tmp = nums[l];
            nums[l] = nums[i];
            nums[i] = tmp;
            dps(nums, l + 1, r, result);
            int tmp2 = nums[l];
            nums[l] = nums[i];
            nums[i] = tmp2;
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        int firstIndex = 0;
        int lastIndex = nums.size() - 1;
        dps(nums, firstIndex, lastIndex, result);
        return result;
    }
};

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        do
        {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }
};