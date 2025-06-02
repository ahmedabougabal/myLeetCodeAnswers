#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPriceSoFar = INT_MAX;
        int maxPrice = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            int profit = prices[i] - minPriceSoFar;
            minPriceSoFar = min(prices[i], minPriceSoFar);
            maxPrice = max(profit, maxPrice);
        }
        return maxPrice;
    }
};
