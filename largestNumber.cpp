#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool customComparison(string a, string b) 
{ 
    return a+b > b+a; 
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result="";
        vector <string> nums_str;
        for(int i=0; i < nums.size();++i){
            nums_str.push_back(to_string(nums[i]));
        }
        sort(nums_str.begin(), nums_str.end(), customComparison);
        for(int j =0; j < nums_str.size(); ++j){
            result+= nums_str[j];
        }
        if(result[0]=='0'){
            return "0";
        }
        return result;
    }
};