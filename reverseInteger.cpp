#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// todo
//  account for integer overflow when dealing with huge numbers as 2^31 - 1
class Solution
{
public:
    int reverse(int x)
    {
        int result;
        // integer to string
        int negativeNum;
        if (x < 0)
        {
            long long newX = static_cast<long long>(x);
            newX *= -1;
            string convertNegativeNumToString = to_string(newX);
            std::reverse(convertNegativeNumToString.begin(), convertNegativeNumToString.end());
            negativeNum = stoi(convertNegativeNumToString);
            return negativeNum * -1;
        }
        else
        {
            string convertNumToString = to_string(x);
            std::reverse(convertNumToString.begin(), convertNumToString.end());
            result = stoi(convertNumToString);
        }
        return result;
    }
};
