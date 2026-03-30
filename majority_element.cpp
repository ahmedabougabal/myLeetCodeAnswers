#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int frequency =0;
        int result = 0;
        for(int i =0; i < nums.size(); ++i){
            frequency = count(nums.begin(), nums.end(), nums[i]);
            if(frequency > nums.size()/2){
                result =  nums[i];
                break;
            }else{
                continue;
            }
        }
        return result;
    }
};