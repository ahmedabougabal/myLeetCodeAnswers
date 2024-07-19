#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix)
  {
    vector<int> result;
    for (int i = 0; i < matrix.size(); i++)
    {
      //* return an iterator to the minNum and dereferencing it to catch the minNum itself
      int minNum = *min_element(matrix[i].begin(), matrix[i].end());
      //* find the index of the minNum by subtracting the iterator to the beginning of the
      //* row from the iterator to the minimum element.
      //! (Method 1 )
      //! int minIndex = min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin();
      //----------
      //! or (Method 2 )
      //(calculates the distance between the iterator
      // pointing to the minimum element and the beginning iterator. => which is the index)
      int minIndex = distance(matrix[i].begin(), find(matrix[i].begin(), matrix[i].end(), minNum));
      bool islucky = true;
      for (int j = 0; j < matrix.size(); j++)
      {
        if (matrix[j][minIndex] > minNum)
        {
          islucky = false;
          break;
        }
      }
      if (islucky)
      {
        result.push_back(minNum);
      }
    }
    return result;
  }
};

int main()
{
  vector<vector<int>> matrix = {
      {3, 7, 8},
      {9, 11, 13},
      {15, 16, 17}};
  Solution sol;
  vector<int> res = sol.luckyNumbers(matrix);
  for (auto i : res)
  {
    cout << i << " "; //! {15}
  }

  return 0;
}

/*
A lucky number is an element of the matrix such
that it is the minimum element in its row and maximum in its column.

[   C  C  C
  r [3,7,8] --> 3
  r [9,11,13], --> 9
  r [15,16,17] --> 15
]
15 is the only lucky number
since it is the minimum in its row and the maximum in its column.




*/