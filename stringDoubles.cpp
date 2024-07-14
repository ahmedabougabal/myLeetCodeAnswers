#include <iostream>
using namespace std;
// ![codewars problem - string doubles ]
string doubles(string s)
{
  string result = "";
  int i = 0;
  while (i < s.size())
  {
    if (i < s.size() - 1 && s[i] == s[i + 1])
    {
      i += 2;
    }
    else
    {
      result += s[i];
      i++;
    }
  }
  return result;
}
