#include <iostream>
#include <set>
using namespace std;


class Solution {
public:
//  A substring is a continuous, smaller sequence of characters taken from a larger string
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int currentLength=0;
        set<char> tracked_chars;
        // char tracker
        for(size_t i =0; i < s.size(); ++i){
            tracked_chars.clear();
            for(size_t j =i; j < s.size(); ++j){
                if(tracked_chars.count(s[j])){
                    break;
                }
                tracked_chars.insert(s[j]);
                currentLength = j - i + 1 ;
                maxLen = max(maxLen, currentLength);
            }
        }
        return maxLen;
    }
};


int main(){
    string Input = "abcabcbb";
    string Input2 = "bbbbbb";
    string Input3 = "";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(Input)<< endl; // should be 3 
    cout << sol.lengthOfLongestSubstring(Input2) << endl; // should be 1
    cout << sol.lengthOfLongestSubstring(Input3) << endl; // should be 0 
    return 0;
}