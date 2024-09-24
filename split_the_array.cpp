#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isPossibleToSplit(vector<int> &nums)
    {
        bool possible = false;
        unordered_map<int, int> map;
        if (nums.size() % 2 != 0)
        {
            return false;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            map[nums[i]]++;
        }
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (it->second > 2)
            {
                possible = false;
                break;
            }
            else
            {
                possible = true;
            }
        }
        return possible;
    }
};

//* could have used a ranged for loop in the second loop in the previous logic
/*
!ranged for loop
        for (const auto &val : map)
        {
            if (val.second > 2)
            {
                possible = false;
                break;
            }
            else
            {
                possible = true;
            }
        }
        return possible;
    }
*/