#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*for better comments visuals, install the 'better comments extension'*/
class Solution
{
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights)
  {
    vector<string> result;
    map<int, string> my_map;
    for (int i = 0; i < heights.size(); i++)
    {
      // since a map in C++ sort what's inside based on the keys
      my_map.insert({-heights[i], names[i]}); //! negated heights to add the heights values into the map descendingly :) */
    }
    //*ranged for loop to extract names from my_map into results vector
    for (auto name : my_map)
    {
      result.push_back(name.second);
    }
    return result;
  }
};
