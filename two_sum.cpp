#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// solution 1 (brute force ) O(N^2)
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         vector<int> result;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             for (int j = i + 1; j < nums.size(); ++j)
//                 if (nums[i] + nums[j] == target)
//                 {
//                     result.push_back(i);
//                     result.push_back(j);
//                 }
//         }
//         return result;
//     }
// };

//! solution 2 using unordered map,, time complexity is O(n)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target) // & for pass by reference and avoid unncecessary copies
    {
        unordered_map<int, int> mp; // O(1) lookups
        for (int i = 0; i < nums.size(); ++i)
        {
            // complement is the other number (you are searching for in the map) that if added to nums[i] (current number) will get you the target
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end())
            {
                return {mp[complement], i}; // return indices of both numbers
            }
            else
            {
                mp[nums[i]] = i; // store the array (nums) values as keys in mp and their indices as values
            }
        }
        return {}; // return an empty vec if no solutions found
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res;
    int target = 9;
    res = sol.twoSum(nums, target);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}
