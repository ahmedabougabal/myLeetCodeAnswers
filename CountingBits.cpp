#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result;
        result.push_back(0);
        for (int i = 0; i <= n; ++i)
        {
            result.push_back(__builtin_popcount(n));
        }
        return result;
    }
};