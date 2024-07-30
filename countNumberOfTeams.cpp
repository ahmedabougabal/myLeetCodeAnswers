#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int numTeams(vector<int> &rating)
  {
    unordered_map<int, int> less;
    unordered_map<int, int> more;
    int count = 0;
    int size = rating.size();
    for (int i = 0; i < size; ++i)
    {
      for (int j = i + 1; j < size; ++j)
      {
        if (rating[i] < rating[j])
        {
          less[i]++;
        }
        else if (rating[i] > rating[j])
        {
          more[i]++;
        }
      }
    }
    for (int i = 0; i < size; ++i)
    {
      for (int j = i + 1; j < size; ++j)
      {
        if (rating[i] < rating[j])
        {
          count += less[j];
        }
        else if (rating[i] > rating[j])
        {
          count += more[j];
        }
      }
    }
    return count;
  }
};
int main()
{
  return 0;
}
///////////////////////////////////////////////
// //! Time limit Exceeded :'(
// //! time complexity : O(n cube)
// #include <iostream>
// #include <vector>
// using namespace std;
// class Solution
// {
// public:
//   int numTeams(vector<int> &rating)
//   {
//     int count = 0;
//     for (int i = 0; i < rating.size(); i++)
//     {
//       for (int j = 0; j < rating.size(); j++)
//       {
//         for (int k = 0; k < rating.size(); k++)
//         {
//           if (i != j && (rating[i] < rating[j] && rating[j] < rating[k]) || ((rating[i] > rating[j]) && (rating[j] > rating[k])))
//           {
//             count++;
//           }
//         }
//       }
//     }
//     return count;
//   }
// };
