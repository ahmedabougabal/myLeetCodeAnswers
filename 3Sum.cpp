#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // void removeTripletDuplicatesFromVectorOfVectors(vector<vector<int>> &vec)
    // {
    //     sort(vec.begin(), vec.end());
    //     auto last = std::unique(vec.begin(), vec.end());
    //     vec.erase(last, vec.end());
    // }

    //[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> triplets;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                    {
                        continue;
                    }

                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        result.push_back({nums[i], nums[j], nums[k]});
                        triplets = {};
                    }
                }
            }
        }
        // removeTripletDuplicatesFromVectorOfVectors(result);
        return result;
    }
};
