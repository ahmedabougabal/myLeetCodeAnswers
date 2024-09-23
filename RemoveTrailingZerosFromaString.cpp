#include <iostream>
using namespace std;

class Solution
{
public:
    string removeTrailingZeros(string num)
    {
        for (int i = num.size() - 1; i >= 0; --i)
        {
            if (num[i] - '0' == 0)
            {
                num.pop_back();
            }
            else
            {
                break;
            }
        }
        return num;
    }
};