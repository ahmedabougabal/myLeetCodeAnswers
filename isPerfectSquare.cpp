#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
using namespace std;

//* optimum solution (binary search)
class Solution
{
public:
  bool isPerfectSquare(int num)
  {
    int left = 0;
    int right = num;
    if (num < 0)
    {
      return false;
    }
    if (num == 0 || num == 1)
    {
      return true;
    }
    while (left <= right)
    {
      long long int mid = (left + right) / 2;
      long long int square = mid * mid;
      if (square == num)
      {
        return true;
      }
      else if (square < num)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return false;
  }
};

//! (brute force) => Time Limit Exceeded
// class Solution
// {
// public:
//   bool isPerfectSquare(int num)
//   {
//     vector<int> PerfectSquareNums;
//     for (int i = 0; i <= num; i++)
//     {
//       int s = sqrt(num);
//       if(s*s == num){
//         PerfectSquareNums.push_back(num);
//       }
//       else
//       {
//         continue;
//       }
//     }
//     // check if num is in the vector
//     for (size_t i = 0; i < PerfectSquareNums.size(); i++)
//     {
//       if (PerfectSquareNums[i] == num)
//       {
//         return true;
//       }
//     }
//     return false;
//   }
// };

int main()
{
  cout << boolalpha;
  Solution sol;
  cout << sol.isPerfectSquare(17) << endl; // should be false
  cout << sol.isPerfectSquare(16) << endl; // should be true
  return 0;
}