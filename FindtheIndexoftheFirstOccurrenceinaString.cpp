#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int res = 0;
        for (int i = 0; i < haystack.size(); ++i)
        {
            if (needle != haystack)
            {
                res--;
                break;
            }
        }
        return res;
    }
};