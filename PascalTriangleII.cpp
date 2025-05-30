#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> result;
        vector<int> v;
        if (rowIndex >= 0)
        {
            result.push_back({1});
        }

        if (rowIndex >= 1)
        {
            result.push_back({1, 1});
        }

        for (int i = 2; i <= rowIndex; ++i)
        {
            vector<int> newRow;
            newRow.push_back(1);
            for (int j = 0; j < i - 1; ++j)
            {
                newRow.push_back(result[i - 1][j] + result[i - 1][j + 1]);
            }
            newRow.push_back(1);
            result.push_back(newRow);
        }
        return result[rowIndex];
    }
};