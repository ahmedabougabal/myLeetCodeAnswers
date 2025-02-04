#include <iostream>
#include <regex>
using namespace std;

class Solution
{
public:
  bool isMatch(string s, string p)
  {
    regex r(p);
    return regex_match(s, r);
  }
};

int main()
{
  return 0;
}