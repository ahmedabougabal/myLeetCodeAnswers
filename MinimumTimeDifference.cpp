#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> minutes;
        for (auto time : timePoints)
        {
            int hrs = stoi(time.substr(0, 3));
            int mins = stoi(time.substr(3, 4));
            minutes.push_back(hrs * 60 + mins);
        }
        sort(minutes.begin(), minutes.end());
        int min_diff = INT_MAX;
        for (int i = 1; i < minutes.size(); ++i)
        {
            min_diff = min(min_diff, minutes[i] - minutes[i - 1]);
        }
        min_diff = min(min_diff, 1440 - abs(minutes.front() - minutes.back()));
        return min_diff;
    }
};