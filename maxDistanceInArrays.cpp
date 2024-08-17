#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int maxDistance(vector<vector<int>> &arrays)
  {
    int min_value = arrays[0].front();
    int max_value = arrays[0][arrays[0].size() - 1];
    int max_dist = 0;
    for (const auto &arr : arrays)
    {
      if (&arr != &arrays[0])
      { // ensuring that we arenot comparing the array withitself
        /*i can remove that if condition if i used the normal for loop */

        max_dist = max(max_dist, max(abs(arr.back() - min_value),
                                     abs(max_value - arr.front())));
      }
      min_value = min(min_value, arr.front());
      max_value = max(max_value, arr.back());
    }
    return max_dist;
  }
};

//! Time limit Exceeded (ineffiecient solution)
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution
// {
// public:
//   int maxDistance(vector<vector<int>> &arrays)
//   {
//     vector<int> distances;
//     for (auto i = 0; i < arrays.size(); ++i)
//     {
//       for (auto j = 0; j < arrays[i].size(); ++j)
//       {
//         for (int n = 0; i < arrays.size(); ++n)
//         {
//           if (i != n)
//           {
//             for (int l = 0; i < arrays[n].size(); ++l)
//             {
//               distances.push_back(abs(arrays[i][j] - arrays[n][l]));
//             }
//           }
//         }
//       }
//     }
//     int n = distances.size() - 1;
//     nth_element(distances.begin(), distances.begin() + n, distances.end());
//     return distances[n];
//   }
// };