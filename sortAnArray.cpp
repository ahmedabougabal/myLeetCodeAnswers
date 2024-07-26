#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
  vector<int> sortArray(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    return nums;
  }
};

/*how std::sort is implemented?

std::sort is a hybrid sorting algorithm called IntroSort

IntroSort Components

Quicksort: IntroSort starts with quicksort, which is known for its fast average-case performance. Quicksort works by selecting a pivot element and partitioning the array into
two sub-arrays around the pivot.
It then recursively sorts these sub-arrays.

Heapsort: If the recursion depth of the quicksort exceeds a certain threshold (typically 2×logn),
IntroSort switches to heapsort.
Heapsort is used to ensure that the worst-case time complexity remains O(nlogn).
Heapsort builds a max-heap and repeatedly extracts the maximum element,
placing it at the end of the array.

Insertion Sort: For small subarrays (typically arrays of size 16 or less),
IntroSort switches to insertion sort. Insertion sort is efficient for small
arrays and can improve overall performance by reducing the overhead of recursive calls.

 */