#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
  string kthDistinct(vector<string> &arr, int k)
  {
    map<string, int> mapped;
    vector<string> result;
    for (int i = 0; i < arr.size(); i++)
    {
      mapped[arr.at(i)]++;
    }
    for (auto str : arr)
    {
      if (mapped[str] < 2)
      {
        result.push_back(str);
      }
    }
    return (result.size() < k) ? "" : (result[k - 1]);
  }
};
// for (auto c : result)
// {
//   cout << c << "\n";
// }

int main()
{
  Solution sol;
  vector<string> arr = {"d", "b", "c", "b", "c", "a"};
  int k = 2; // 2-1 = 1
  cout << endl;
  cout << sol.kthDistinct(arr, k) << endl;
  return 0;
}
