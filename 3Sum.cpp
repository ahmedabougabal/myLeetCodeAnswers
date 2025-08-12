#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int removeDuplicatesFromSortedVectors(vector<int> nums)
    {
        int unique = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[unique])
            {
                unique++;
                nums[unique] = nums[i];
            }
        }
        return unique + 1;
    }

    void removeTripletDuplicatesFromVectorOfVectors(vector<vector<int>> vec)
    {
        sort(vec.begin(), vec.end());
        auto last = std::unique(vec.begin(), vec.end());
        vec.erase(last, vec.end());
    }

    //[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> triplets;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                for (int k = j + 1; k < nums.size(); ++k)
                {

                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        result.push_back({nums[i], nums[j], nums[k]});
                        triplets = {};
                    }
                }
            }
        }
        removeTripletDuplicatesFromVectorOfVectors(result);
        return result;
    }
};
