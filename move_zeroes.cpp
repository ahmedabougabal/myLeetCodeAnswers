#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_count=0;
        for(int i =0; i < nums.size(); ++i){
            if(nums[i]==0 ){
                nums.erase(nums.begin() + i);
                zero_count++;
            }else{
                continue;
            }
        }

        while(zero_count > 0){
            nums.push_back(0);
            zero_count--;
        }
    }
};

