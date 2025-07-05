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
        return low;
    }

    int searchInsert(vector<int> &nums, int target)
    {
        int result;
        return binarySearch(0, nums.size() - 1, nums, target);
    }
};