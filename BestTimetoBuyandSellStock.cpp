#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

//! passes only 50 testcases (approach using 2 pointers)
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int left_ptr = 0;
//         int right_ptr = prices.size() - 1;
//         int max = 0;
//         while (right_ptr >= left_ptr)
//         {
//             int sum = prices[right_ptr] - prices[left_ptr];
//             if (sum > max)
//             {
//                 max = sum;
//                 left_ptr++;
//             }
//             right_ptr--;
//         }
//         return max;
//     }
// };
