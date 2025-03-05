#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

bool isAnagram(const string &test, const string &original)
{
  unordered_map<char, int> mp;
  string lower_test = "";
  string lower_original = "";

  if (test.size() != original.size())
  {
    return false;
  }

  for (const char &c : test)
  {
    lower_test += tolower(c);
  }
  for (const char &c : original)
  {
    lower_original += tolower(c);
  }
  for (int i = 0; i < lower_test.size(); ++i)
  {
    mp[lower_test[i]]++;
  }

  for (int i = 0; i < lower_original.size(); ++i)
  {
    mp[lower_original[i]]--;
  }

  for (const auto &pair : mp)
  {
    if (pair.second != 0)
    {
      return false;
    }
  }
  return true;
}