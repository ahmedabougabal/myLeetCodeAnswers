#include <iostream>
#include <string>
using namespace std;

string find_screen_height(int width, const string &ratio)
{
  string result = "";
  string str_width = to_string(width);
  result += str_width + "x";
  string ex1 = "";
  string ex2 = "";
  for (auto c : ratio)
  {
    if (c == ':')
    {
      break;
    }
    ex1 += c;
  }
  for (size_t i = 0; i <= ratio.length(); ++i)
  {

    if (ratio[i] == ':')
    {
      ex2 += ratio[i + 1];
    }
  }
  cout << "extracted 1 = " << ex1 << "\n"; // debugging
  cout << "extracted 2 = " << ex2 << "\n"; // debugging
  int calc = (width * stoi(ex2)) / stoi(ex1);
  string ratio_calc = to_string(calc);
  result += ratio_calc;
  return result;
}

int main()
{
  // int w = 434;
  // string str_width = to_string(w);
  // str_width += "s";
  // cout << str_width;
  // test case
  cout << find_screen_height(1024, "4:3");
  return 0;
}
