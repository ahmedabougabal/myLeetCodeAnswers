#include <iostream>
#include <string>
using namespace std;

// class Solution
// {
// public:
string reverseParentheses(string s)
{
  string result = "";
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (s[i] == '(' || s[i] == ')')
    {
      continue;
    }
    result += s[i];
  }
  cout << endl;
  return result;
}
// };

int main()
{

  string s = "(abcd)";
  cout << reverseParentheses(s);
  return 0;
}