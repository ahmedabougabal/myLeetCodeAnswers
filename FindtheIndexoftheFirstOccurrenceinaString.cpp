#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        if (needle.size() > haystack.size())
        {
            return -1;
        }
        if (needle.size() == 0)
        {
            return 0;
        }

        for (int i = 0; i <= haystack.size() - needle.size(); ++i)
        {
            if (haystack.substr(i, needle.size()) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};
