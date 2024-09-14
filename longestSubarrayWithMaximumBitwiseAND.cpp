#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//! need to find the largest element which is also has the largest bitwise 
//! AND value in the vector and count the max length of its sequential occurances 
class Solution {
public:
    int longestSubarray(vector<int>& nums) { 
      int largest = *max_element(nums.begin(), nums.end());
      vector<int>result;
      int max_len =0;
      int curr_len =0;
      for(int i=0; i < nums.size(); ++i){
        
        if(nums[i]==largest ){
          curr_len++;
          max_len = max(max_len,curr_len);
        } 
        else {
          curr_len=0;
        }
      }
      return max_len;
    }
};

