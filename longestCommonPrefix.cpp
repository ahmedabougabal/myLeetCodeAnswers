#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // find the lenght of the shortest string in strs
    int shortestString(vector<string> vec)
    {
        int stringWithLeastSize = vec[0].size();
        if (vec.empty())
        {
            return 0;
        }
        for (auto i = 1; i < vec.size(); ++i)
        {
            if (vec[i].size() < stringWithLeastSize)
            {
                stringWithLeastSize = vec[i].size();
            }
        }
        return stringWithLeastSize;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        auto vector_size = strs.size();
        string result = "";

        int stringWithLeastSize = shortestString(strs);
        for (int i = 0; i < stringWithLeastSize; ++i)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j)
            {
                if (strs[j][i] != c)
                {
                    return result;
                }
            }
            result += c;
        }
        return result;
    }
};