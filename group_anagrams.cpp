#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
//! if 2 words' sorting is the same, then they are anagrams :)
class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> anagrams;
    for (auto str : strs)
    {
      string sorted = str;
      sort(sorted.begin(), sorted.end());
      anagrams[sorted].push_back(str);
    }
    vector<vector<string>> result;
    for (auto pair : anagrams)
    {
      result.push_back(pair.second);
    }
    return result;
  }
};
