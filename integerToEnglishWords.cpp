#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
  string numberToWords(int num)
  {
    if (num == 0)
    {
      return "Zero";
    }
    map<int, string> d = {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
        {100, "Hundred"},
        {1000, "Thousand"},
        {1000000, "Million"},
        {1000000000, "Billion"}};
    vector<string> result;
    if (num >= 1000000000)
    {
      result.push_back(numberToWords(num / 1000000000)); // recursive approach to see whether it is one , or two or three billions
      result.push_back("Billion");
      num %= 1000000000; // leaves num with the part of the number that is less than one billion, which will be processed in the next steps.
    }
    if (num >= 1000000)
    {
      result.push_back(numberToWords(num / 1000000));
      result.push_back("Million");
      num %= 1000000;
    }
    if (num >= 1000)
    {
      result.push_back(numberToWords(num / 1000));
      result.push_back("Thousand");
      num %= 1000;
    }
    if (num >= 100)
    {
      result.push_back(numberToWords(num / 100));
      result.push_back("Hundred");
      num %= 100;
    }
    if (num >= 20)
    {
      result.push_back(d[(num / 10) * 10]);
      num %= 10;
    }
    if (num > 0)
    {
      result.push_back(d[num]);
    }
    string final_result = "";
    for (size_t i = 0; i < result.size(); i++)
    {
      if (i > 0)
      {
        final_result += " "; // handle spacing between the words
      }
      final_result += result[i];
    }
    return final_result;
  }
};
