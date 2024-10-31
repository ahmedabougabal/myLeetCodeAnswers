/**Have the function stringchallenge (str) take the str
parameter being passed and modify it using the following
algorithm. Replace every letter in the string with the letter
following it in the alphabet (e. c becomes d, z becomes a). Then
capitalize every vowel in this new string (a, e, i, o, u) and finally
return this modified string.**/
// Examples
// Input: "hello*3"
// Output: Ifmmp*3
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
string StringChallenge(string str)
{
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  unordered_map<char, char> alphabet_map;
  //* build the alphabet map for both lower and upper cases
  for (int i = 0; i < alphabet.length(); ++i)
  {
    if (i == alphabet.length() - 1)
    {
      alphabet_map[alphabet[i]] = 'a'; // if it is z , the next is a
      alphabet_map[toupper(alphabet[i])] = 'A';
    }
    else
    {
      alphabet_map[alphabet[i]] = alphabet[i + 1];
      alphabet_map[toupper(alphabet[i])] = toupper(alphabet[i + 1]);
    }
  }

  string result = "";
  for (char c : str)
  {
    if (isalpha(c))
    {
      char next_letter = alphabet_map[c];
      // if next letter is a vowel, then capitalize
      char lower_next = tolower(next_letter);
      if (find(vowels.begin(), vowels.end(), lower_next) != vowels.end())
      {
        next_letter = toupper(next_letter);
      }
      result += next_letter;
    }
    else
    {
      result += c;
    }
  }
  return result;
}
int main()
{
  cout << StringChallenge("hello*3");
  return 0;
}
