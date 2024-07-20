#include <iostream>
using namespace std;

//! Method 1
// class Solution
// {
// public:
//   bool isPalindrome(int x)
//   {
//     string reversed = "";
//     string converted = to_string(x);
//     for (int i = converted.size()-1; i >= 0; i--)
//     {
//       reversed += converted[i];
//     }
//     return converted != reversed;
//   }
// };
//! Method 2 using reverse algo
#include <algorithm>
class Solution
{
public:
  bool isPalindrome(int x)
  {
    string original = to_string(x);
    string reversed = original;
    reverse(reversed.begin(), reversed.end());
    return original == reversed;
  }
};

int main()
{
  cout << boolalpha;
  int x = 121;
  Solution sol;
  bool isIt = sol.isPalindrome(x);
  cout << isIt << endl;
  return 0;
}