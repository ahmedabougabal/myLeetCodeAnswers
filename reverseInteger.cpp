#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

// todo
//  account for integer overflow when dealing with huge numbers as 2^31 - 1
// need to refactor this static cast logic
class Solution
{
public:
    int reverse(int x)
    {
        long long result;
        if (x >= INT_MAX || x <= INT_MIN)
        {
            return 0;
        }
        // integer to string
        long long negativeNum;
        if (x < 0)
        {
            x *= -1;
            string convertNegativeNumToString = to_string(x);
            std::reverse(convertNegativeNumToString.begin(), convertNegativeNumToString.end());
            negativeNum = stoll(convertNegativeNumToString) * -1;
            return negativeNum;
        }
        else
        {
            string convertNumToString = to_string(x);
            std::reverse(convertNumToString.begin(), convertNumToString.end());
            result = stoll(convertNumToString);
        }
        return result;
    }
};
