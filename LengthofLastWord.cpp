#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    std::string trim(const std::string &str,
                     const std::string &whitespace = " \t")
    {
        const auto strBegin = str.find_first_not_of(whitespace);
        if (strBegin == std::string::npos)
            return ""; // no content

        const auto strEnd = str.find_last_not_of(whitespace);
        const auto strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
    }
    int lengthOfLastWord(string s)
    {
        string trimmedString = trim(s, " \t");
        int size = trimmedString.size() - 1;
        int result = 0;

        for (int i = size; i >= 0; --i)
        {
            if (trimmedString[i] == ' ')
            {
                break;
            }
            result++;
        }
        return result;
    }
};

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        const auto end = s.find_last_not_of(' ');
        const auto start = s.find_last_of(' ', end);
        return end - start;
    }
};

// a more simpler approach

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int result = 0;
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }

        while (i >= 0 && s[i] != ' ')
        {
            result++;
            i--;
        }
        return result;
    }
};