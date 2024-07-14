#include <iostream>
using namespace std;
// ![codewars problem - string doubles ]
string doubles(string s)
{
  string result = "";
  for (int current : s)
  {
    if (result.empty() || current != result.back())
    {
      result.push_back(current);
    }
    else
    {
      result.pop_back();
    }
  }
  return result;
}