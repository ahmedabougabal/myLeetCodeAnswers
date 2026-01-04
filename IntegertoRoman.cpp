#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string>> values = {
            {1000, "M"},
            {900 ,"CM"} ,
            {500, "D"},
            {400 ,"CD"} ,
            {100, "C"},
            {90 ,"XC"} ,
            {50, "L"},
            {40 ,"XL"}  ,
            {10, "X"},
            {9 ,"IX"}  ,
            {5, "V"},
            {4 ,"IV"} ,
            {1, "I"}};
            auto convertNumToString = to_string(num);

        string result = "";
        
        for(size_t i =0; i < values.size(); ++i){
            while(num >= values[i].first){
                result+=values[i].second;
                num-=values[i].first;
            }
        }
        
        return result;
    }
};

