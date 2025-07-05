#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int binarySearch(int low, int high, vector<int> vec, int target)
    {
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (target == vec[mid])
            {
                return mid;
            }
            else if (target > vec[mid])

                low = mid + 1;

            else

                high = mid - 1;
        }
        return;
    }

    int searchInsert(vector<int> &nums, int target)
    {
        int result;
        if (target)
        {
            result = binarySearch(0, nums.size() - 1, nums, target);
        }
        else
        {
            nums.push_back(target);
            sort(nums.begin(), nums.end());
            result = binarySearch(0, nums.size() - 1, nums, target);
        }

        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     if (nums[i] == target)
        //     {
        //         result = i;
        //         break;
        //     }
        //     else
        //     {
        //         nums.push_back(target);
        //         sort(nums.begin(), nums.end());
        //         // auto it = lower_bound(nums.begin(), nums.end(), target);
        //         for (int i = 0; i < nums.size(); ++i)
        //         {
        //             if (nums[i] == target)
        //             {
        //                 result = i;
        //             }
        //         }
        //     }
        // }
        return result;
    }
};