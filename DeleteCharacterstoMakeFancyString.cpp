#include <iostream>
using namespace std;

class Solution
{
public:
  string makeFancyString(string s)
  {
    string result = "";
    for (int i = 0; i < s.size(); ++i)
    {
      if (i + 2 < s.size())
      {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
        {
          result += s[i];
          result += s[i + 1];
          i += 2;
        }
        else
        {
          result += s[i];
        }
      }
    }
    return result;
  }
};

int main()
{
  Solution sol;
  cout << sol.makeFancyString("leeetcode"); // should be "leetcode"
  return 0;
}