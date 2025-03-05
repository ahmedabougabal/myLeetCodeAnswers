#include <iostream>
#include <vector>
using namespace std;

//! solution 1
class Solution1
{
public:
  void reverseString(vector<char> &s)
  {
    reverse(s.begin(), s.end());
  }
};

//! solution 2 (two-pointer approach)
class Solution2
{
public:
  void reverseString(vector<char> &s)
  {
    int r = 0;
    int l = s.size() - 1;
    while (r < l)
    {
      swap(s[r], s[l]);
      r++;
      l--;
    }
  }
};
