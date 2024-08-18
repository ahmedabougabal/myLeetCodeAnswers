#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//! Ugly numbers are positive integers whose prime factors are limited to 2, 3, and 5.
class Solution
{
public:
  int nthUglyNumber(int n)
  {
    int i2 = 0, i3 = 0, i5 = 0; // 3 acting Pointers
    vector<int> ugly_nums(n);   // why do i resize ? to allocate the necessary memory needed
    // i can just declare the vector without resizing but i should then use push_back which is
    // ineffecient as it reallocates the memory each time u add an element and then copy elements each time

    //* note that the following line only works if the vector is resized otherwise it will lead to error
    ugly_nums[0] = 1; // The first ugly number is 1, i can use .push_back if i am not resizing

    for (int i = 1; i < n; ++i)
    {
      // Find the next ugly number by taking the minimum of the current ugly numbers in the vector multiplied by 2, 3, and 5.
      int next_ugly = min({ugly_nums[i2] * 2, ugly_nums[i3] * 3, ugly_nums[i5] * 5});
      ugly_nums[i] = next_ugly; // Append the next ugly number to the sequence.

      // Increment the corresponding pointer(s) if the next ugly number was chosen from
      // multiplying by 2, 3, or 5.
      if (next_ugly == ugly_nums[i2] * 2)
        i2++;
      if (next_ugly == ugly_nums[i3] * 3)
        i3++;
      if (next_ugly == ugly_nums[i5] * 5)
        i5++;
    }

    return ugly_nums.back(); // since the required output is the last ugly number in the vector
  }
};