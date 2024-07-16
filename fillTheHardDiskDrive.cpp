#include <iostream>
#include <vector>
using namespace std;

// Examples:
//* save([4,4,4,3,3], 12) -> 3
//* # 4+4+4 <= 12, but 4+4+4+3 > 12
//!--------------------------------------
//* save([4,4,4,3,3], 11) -> 2
//* # 4+4 <= 11, but 4+4+4 > 11
//!--------------------------------------
//* save([12, 0, 0, 1], 12) -> 3
//* # 12+0+0 <= 12, but 12+0+0+1 > 12

int save(vector<int> sizes, int hd)
{
  int count = 0;
  int sum = 0;
  for (int i = 0; i < sizes.size(); i++)
  {
    sum += sizes[i];
    if (sum <= hd)
    {
      count++;
    }
    else
    {
      return count;
      break;
    }
  }
  return count;
}