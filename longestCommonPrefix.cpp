#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        auto vector_size = strs.size();
        string result = "";
        // find the lenght of the shortest string in strs
        int min_lenght_of_strings;
        for (int i = 0; i < min_lenght_of_strings; ++i)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j)
            {
                if (strs[j][i] != c)
                {
                    result += c;
                }
            }
        }
        return result;
    }
};