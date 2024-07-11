#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string reverseParentheses(string s)
  {
    stack<string> st;
    string current;

    for (char c : s)
    {
      if (c == '(')
      {
        st.push(current);
        current = "";
      }
      else if (c == ')')
      {
        reverse(current.begin(), current.end());
        if (!st.empty())
        {
          current = st.top() + current;
          st.pop();
        }
      }
      else
      {
        current += c;
      }
    }

    return current;
  }
};

int main()
{
  Solution sol;
  string input = "(u(love)i)";
  cout << sol.reverseParentheses(input) << endl; // Output: "iloveu"
  return 0;
}
