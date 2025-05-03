#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//! using full vector sorting (works but needs optimization)
// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         sort(nums.begin(), nums.end()); // time complexity is O(n*logn)
//         int vector_size = nums.size();
//         int index = vector_size - k;
//         return nums[index];
//     }
// };

// optimization from O(n log n) to O (n log k) using priority queue
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // k will be the size of the priority queue (min heap) where the top of this queue will be the result we seek
        priority_queue<int, vector<int>, greater<int>> q;
        // set the size of min heap to k
        for (auto i : nums)
        {
            // check if the 2 nodes inside the min heap has the top largest elements from the nums vector
            q.push(i);
            if (q.size() > k)
            {
                q.pop();
            }
        }
        return q.top();
    }
};
