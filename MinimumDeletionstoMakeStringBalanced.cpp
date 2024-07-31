#include <iostream>
using namespace std;

class Solution
{
public:
  int minimumDeletions(string s)
  {
    int deletions = 0;
    int bCount = 0;
    for (auto c : s)
    {
      if (c == 'a')
      {
        if (bCount > deletions) // encountered an 'a' after Bs ?
        {
          deletions++; // remove these As
        }
      }
      else
      {
        bCount++;
      }
    }
    return deletions;
  }
};

//! another solution : using the min function
// #include <iostream>
// #include <string>
// using namespace std;

// class Solution
// {
// public:
//   int minimumDeletions(string s)
//   {
//     int deletions = 0;
//     int bCount = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//       if (s[i] == 'b')
//       {
//         bCount++;
//         // we encountered the letter 'a' after 'b',
//         // we now need to remove the letter 'a' or delete all prev Bs to make the string balanced
//       }
//       else if (s[i] == 'a')
//       {
//         deletions = min(deletions + 1, bCount);
//       }
//     }
//     return deletions;
//   }
// };
