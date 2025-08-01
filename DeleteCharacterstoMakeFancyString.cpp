#include <iostream>
using namespace std;

class Solution
{
public:
  string makeFancyString(string s)
  {
    string result = "";
    if (s.empty())
    {
      return "";
    }
    int count = 1;
    result += s[0];

    for (int i = 1; i < s.size(); ++i)
    {
      if (s[i] == s[i - 1])
      {
        count++;
      }
      else
      {
        count = 1;
      }
      if (count < 3)
      {
        result += s[i];
      }
    }
    return result;
  }
};

int main()
{
  Solution sol;
  cout << sol.makeFancyString("leeetcode") << endl; // should be "leetcode"
  cout << sol.makeFancyString("aaabaaaa");          // should be "leetcode"
  return 0;
}