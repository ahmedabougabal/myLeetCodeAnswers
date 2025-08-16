#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long long result;
        // integer to string
        long long negativeNum;
        if (x < 0)
        {
            long long newX = static_cast<long long>(x * 1);
            newX *= -1;
            string convertNegativeNumToString = to_string(newX);
            std::reverse(convertNegativeNumToString.begin(), convertNegativeNumToString.end());
            negativeNum = stoll(convertNegativeNumToString) * -1;
            if (negativeNum < INT_MIN)
            {
                return 0;
            }
            return negativeNum;
        }
        else
        {
            string convertNumToString = to_string(x);
            std::reverse(convertNumToString.begin(), convertNumToString.end());
            result = stoll(convertNumToString);
            if (result > INT_MAX)
            {
                return 0;
            }
        }
        return result;
    }
};
