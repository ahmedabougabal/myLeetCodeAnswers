#include <iostream>
#include <string>
using namespace std;

string find_screen_height(int width, const string &ratio)
{
  string result = "";
  // bug: convert 'ratio' string to integers to prevent exceptions
  int num = 0, den = 0;
  auto colon = ratio.find_first_of(':');
  for (int i = 0; i < colon; ++i)
  {
    auto c = ratio[i];
    num = num * 10 + c - '0';
  }
  for (int j = colon + 1; j < ratio.size(); ++j)
  {
    auto m = ratio[j];
    den = den * 10 + m - '0';
  }
  int height = (width * den) / num;
  // then, convert the int to string to concatenate altogether in the final result
  string h = to_string(height);
  string w = to_string(width);
  result += w + "x" + h;
  return result;
}