#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{

public:
  vector<int> arrayRankTransform(vector<int> &arr)
  {
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    unordered_map<int, int> myMap;
    int rank = 1;
    for (auto i = 0; i < sorted_arr.size(); ++i)
    {
      if (myMap.find(sorted_arr[i]) == myMap.end())
      {
        myMap[sorted_arr[i]] = rank;
        rank++;
      }
    }
    vector<int> res(arr.size());
    for (auto i = 0; i < arr.size(); ++i)
    {
      res[i] = myMap[arr[i]];
    }
    //* debugging
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    {
      cout << it->first << " " << it->second << endl;
    }
    cout << "\n===========\n";
    for (int val : res)
    {
      cout << val << " ";
    }
    return res;
  }
};

// "\n===============\n";
/*
arr = [40,10,20,30]
Output: [4,1,2,3]
*/

int main()
{
  Solution sol;
  vector<int> vec = {40, 10, 20, 30, 40};
  sol.arrayRankTransform(vec);
  return 0;
}

// private:
//   vector<int> count_if_smaller(const vector<int> &v)
//   {
//     vector<int> result(v.size());
//     transform(v.begin(), v.end(), result.begin(),
//               [&](int x)
//               {
//                 return count_if(v.begin(), v.end(), [&](int y)
//                                 { return y < x; });
//               });
//     return result;s
//   }

// class Solution
// {

// public:
//   vector<int> arrayRankTransform(vector<int> &arr)
//   {
//     vector<int> sorted_arr = arr;
//     sort(sorted_arr.begin(), sorted_arr.end());
//     unordered_map<int, int> myMap;
//     vector<int> res(arr.size());
//     int rank = 1;
//     for (auto i = 0; i < sorted_arr.size(); ++i)
//     {
//       if (sorted_arr[i] == sorted_arr[i + 1] && i < sorted_arr.size() - 1)
//       {
//         myMap[sorted_arr[i]] = myMap[sorted_arr[i + 1]] = rank;
//       }
//       else
//       {
//         myMap[sorted_arr[i]] = rank;
//         rank++;
//       }
//     }
//     for (auto it = myMap.begin(); it != myMap.end(); ++it)
//     {
//       cout << it->first << " " << it->second << endl;
//       res.push_back(it->second);
//     }
//     cout << "\n===========\n";
//     for (int num : arr)
//     {
//       res.push_back(num);
//     }
//     for (int val : res)
//     {
//       cout << val << " ";
//     }
//     return res;
//   }
// };
