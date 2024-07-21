#include <iostream>
using namespace std;
#include <stack>
class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> sk;
    for (auto i : s)
    {
      switch (i)
      {
      case '{':
      case '(':
      case '[':
        sk.push(i);
        break;
      case '}':
        if (sk.empty() || sk.top() != '{')
        {
          return false;
        }
        else
        {
          sk.pop();
        }
        break;
      case ')':
        if (sk.empty() || sk.top() != '(')
        {
          return false;
        }
        else
        {
          sk.pop();
        }
        break;
      case ']':
        if (sk.empty() || sk.top() != '[')
        {
          return false;
        }
        else
        {
          sk.pop();
        }
        break;
      default:
        return false;
        break;
      }
    }
    return sk.empty();
  }
};
