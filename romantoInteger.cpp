#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int romanToInt(string s)
  {
    unordered_map<char, int> umap;
    char chars[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int vals[] = {1, 5, 10, 50, 100, 500, 1000};
    int sum = 0;

    for (auto i = 0; i < sizeof(chars) / sizeof(chars[0]); ++i)
    {
      umap[chars[i]] = vals[i];
    }
    for (int j = 0; j < s.size(); j++)
    {
      if (umap[s[j]] < umap[s[j + 1]] && j + 1 < s.size())
      {
        sum -= umap[s[j]];
      }
      else
      {
        sum += umap[s[j]];
      }
    }
    return sum;
  }
};