#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int totalPrice = 0;
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            if (prices[i] < prices[i + 1])
            {
                totalPrice += prices[i + 1] - prices[i];
            }
        }
        return totalPrice;
    }
};