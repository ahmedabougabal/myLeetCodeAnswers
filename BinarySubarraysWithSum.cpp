#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//! find the number of non-empty subarrays in a given binary array nums that sum up to a specified integer goal.

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> map;
        int current_sum=0;
        int count = 0;
        map[0]=1;
        for(int num : nums){
            current_sum+= num;
            if(map.find(current_sum-goal) !=map.end()){
                count+=map[current_sum-goal];
            }
            map[current_sum]++;
        }
        return count;
    }
};