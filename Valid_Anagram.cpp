#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    unordered_map<char, int> mymap;
    if (s.size() != t.size())
    {
      return false;
    }
    for (int i = 0; i < s.size(); i++)
    {
      mymap[s[i]]++;
    }
    for (int j = 0; j < t.size(); j++)
    {
      mymap[t[j]--];
      if (mymap[t[j]] < 0)
      {
        return false;
      }
    }
    return true;
  }
};