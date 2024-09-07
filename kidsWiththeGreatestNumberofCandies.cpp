#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      int n= candies.size();
      vector<bool> result(n);
      int largest = *max_element(candies.begin(), candies.end());
      for (int i = 0; i < n; ++i) {
        if (candies[i] + extraCandies >= largest ) {
            result[i]= true;
        } else {
          result[i]= false;
          }
      }
      return result;
    }
};