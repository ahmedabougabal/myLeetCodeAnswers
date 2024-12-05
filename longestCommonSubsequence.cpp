#include <iostream>
#include <vector>
using namespace std;
//**************! not yet finished***************
class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int res = 0;
    string same = "";
    if (text1.size() == text2.size())
    {
      return text1.size();
    }
    else
    {
      return res;
    }
    for (int i = 0; i < text1.size(); i += 2)
    {
      same += text1[i];
      if (same == text2)
      {
        res += same.size();
      }
    }
    return res;
  }
};