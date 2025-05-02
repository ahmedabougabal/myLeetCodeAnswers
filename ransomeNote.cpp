#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        bool result;
        unordered_map<char, int> hashMap;
        for (char a : magazine)
        {
            hashMap[a]++;
        }
        for (char c : ransomNote)
        {
            if (hashMap[c] == 0)
                return false;
            hashMap[c]--;
            result = true;
        }
        return result;
    }
};