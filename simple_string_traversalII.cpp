#include <iostream>
#include <algorithm>
using namespace std;

string solve(string s, int a, int b)
{
  string result = "";
  if (b < s.size())
  {
    reverse(s.begin() + a, s.begin() + b + 1);
  }
  else
  {
    reverse(s.begin() + a, s.end());
  }
  return s;
}

int main()
{
  string s1 = solve("codewars", 1, 5); // cawedors
  cout << s1;
  return 0;
}