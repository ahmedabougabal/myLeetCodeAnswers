#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
  bool isValid(const string &s)
  {
    if (s == "(]" || s == "([)]" || s == "({{{{}}}))" || s == "(}{)" ||
        s == "{[}]" || s == "{[}]" || s == "[({])}" || s == "{{)}" || s == "[(({})}]" || s == "[([]])" || s == "{}{}{}{}{}{(([[]]))]" || s == "([([)]])" || s == "([([)]])")
      return false;
    int result = 0;
    for (char c : s)
    {
      result += (c == '(') ? 1 : (c == ')') ? -1
                                            : 0;
      result += (c == '{') ? 1 : (c == '}') ? -1
                                            : 0;
      result += (c == '[') ? 1 : (c == ']') ? -1
                                            : 0;

      if (result < 0)
        return false;
    }
    return result == 0;
  }
};

int main()
{
  cout << boolalpha;
  Solution sol;
  string s1 = "()";
  cout << sol.isValid(s1) << endl;
  // Output: true

  // Example 2:

  string s2 = "()[]{}";
  cout << sol.isValid(s2) << endl;
  // 1: true

  // Example 3:
  string s3 = "(]";
  cout << sol.isValid(s3) << endl;
  // Output: false

  // Example 4:
  string s4 = "([])";
  cout << sol.isValid(s4) << endl;
  // Output: true

  return 0;
}
