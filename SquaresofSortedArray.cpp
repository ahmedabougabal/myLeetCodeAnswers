// #include <iostream>
// #include <vector>
// #include <algorithm>

// class Solution
// {
// public:
//     vector<int> sortedSquares(vector<int> &nums)
//     {
//         vector<int> result;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             result.push_back(nums[i] * nums[i]);
//         }
//         sort(result.begin(), result.end());
//         return result;
//     }
// };

//* optimized version time : O(n log n) , space : O(n) or O (log n) , no built in sort (2 pointers)
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;
        int idx_to_place_elem = nums.size() - 1;
        vector<int> result(nums.size());
        while (ptr1 <= ptr2)
        {
            if (abs(nums[ptr2]) > abs(nums[ptr1]))
            {
                result[idx_to_place_elem] = nums[ptr2] * nums[ptr2];
                ptr2--;
                idx_to_place_elem--;
            }
            else
            {
                result[idx_to_place_elem] = nums[ptr1] * nums[ptr1];
                ptr1++;
                idx_to_place_elem--;
            }
        }
        return result;
    }
};