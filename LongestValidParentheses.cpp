#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  int longestValidParentheses(const string &s)
  {
    stack<int> mystack;
    mystack.push(-1);
    int res = 0;
    if (s == "")
    {
      res = 0;
    }
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == '(')
      {
        mystack.push(i);
      }
      else // s[i] == ')' --> invalid starting point
      {
        mystack.pop();
        if (mystack.empty())
        {
          mystack.push(i);
        }
        else
        {
          res = max(i - mystack.top(), res); // res =(1-(-1)) when encountering '()' ,
          // that's why i initilaized the stack with -1 :D
        }
      }
    }
    return res;
  }
};

int main()
{
  //! adds LC's test cases for validation and testing
  Solution sol;
  string s1 = "(()";
  cout << sol.longestValidParentheses(s1) << "\n";
  cout << "=========================\n";
  string s2 = ")()())";
  cout << sol.longestValidParentheses(s1) << "\n";
  cout << "=========================\n";
  string s3 = "";
  cout << sol.longestValidParentheses(s3) << "\n";
  return 0;
}