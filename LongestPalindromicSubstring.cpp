#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> expandAroundCenters(int left, int right, const string &s)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
        {
            return s;
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            // checking for odd length palindromes
            auto [left1, right1] = expandAroundCenters(i, i, s);
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }

            // checking for even length palindromes
            auto [left2, right2] = expandAroundCenters(i, i + 1, s);
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};