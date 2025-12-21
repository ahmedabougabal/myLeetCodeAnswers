#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int LCS(int i, int j,const string& text1,const string& text2, vector<vector<int>>&dp){

        
        
        if(i == text1.size() || j == text2.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            dp[i][j]= 1 + LCS(i+1, j+1, text1, text2, dp);
        }

        //B) LCS(i+1, j) and LCS(i, j+1)
        else
        {
            dp[i][j]  = max(LCS(i+1, j, text1, text2, dp) ,LCS(i, j+1, text1, text2, dp));
        }
        
        return dp[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2)
    {
        
        int m =text1.size(); 
        int n = text2.size() ;
        vector<vector<int>> dp(m, vector<int>(n, -1));  

        return LCS(0,0,text1, text2, dp);
    }
};