#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
  // ! memo table as a 2d vector to store computed results
  vector<vector<int>> memo;
  int lcs(const string &text1, const string &text2, int i, int j)
  {
    // adding a base case (as for the recursive approach)
    if (i == text1.size() || j == text2.size())
    {
      return 0;
    }
    // check for precomputed values in memo
    if (memo[i][j] != -1) // means that if they hold values (it has been used , so retain the values inside)
    {
      return memo[i][j];
    }
    if (text1[i] == text2[j]) //! match
    {
      // if both letters are same in both strings (then add 1 and the func recursive call)
      memo[i][j] = 1 + lcs(text1, text2, i + 1, j + 1);
      return memo[i][j];
    }
    //! no match
    int first_skip = lcs(text1, text2, i + 1, j);
    int second_skip = lcs(text1, text2, i, j + 1);
    memo[i][j] = max(first_skip, second_skip);
    return memo[i][j];
  }

public:
  int longestCommonSubsequence(string text1, string text2)
  {
    // initialize the memo
    //! assinging a number of vectors of a fixed size inside memo and their count is the same size of string text1 param
    memo.assign(text1.length(), vector<int>(text2.length(), -1));
    return lcs(text1, text2, 0, 0);
  }
};

int main()
{
  return 0;
}