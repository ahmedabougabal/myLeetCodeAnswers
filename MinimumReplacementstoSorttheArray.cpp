#include <iostream>
#include <vector>
using namespace std;
/**
, from my base of understanding , non decreasing means arranging the numbers in ascending order WHILE HAVING DUPLICATES
example [10 , 5  ,13 ] => not sorted.
we have to split 10 to numbers that add up and equal the next number.

5 , 5 , 5 , 13 --> this is non decreasing order but can't be ascending cuz it have duplicates, the question needs to find the minimum number of times we need to split numbers to sort the array?
so since we splitted only 10 to 5 and 5 then we return 1 , as 1
was the min num of times we have to split a number to keep the array sorted.
*/
class Solution
{
public:
  long long minimumReplacement(vector<int> &nums)
  {
    long long res = 0;
    int n = nums.size();
    int max_allowed_value = nums[n - 1]; // starting from the last element
    for (int i = n - 2; i >= 0; --i)
    {
      int k;
      if (nums[i] <= res)
      {
        max_allowed_value = nums[i];
        continue;
      }
      else
      {
        k = (nums[0] + max_allowed_value - 1); // 10 +  mx(5) -1 // mx (5) = 2
        res = nums[0] / k;
      }
    }
    return res;
  }
};

int main()
{
  vector<int> v = {10, 5, 13};
  Solution sol;
  cout << sol.minimumReplacement(v);
  return 0;
}