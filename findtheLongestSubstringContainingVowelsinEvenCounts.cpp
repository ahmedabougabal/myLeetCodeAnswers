#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int findTheLongestSubstring(string s) {
      unordered_map<int, int> map;
      int bitmask =0;
      int max_len=0;
      map[0]=-1;
      for(int i =0 ; i < s.size();++i){
        char c= s[i];
        if(c=='a') bitmask = bitmask ^ (1 << 0);
        if(c=='e') bitmask = bitmask ^ (1 << 1);
        if(c=='i') bitmask = bitmask ^ (1 << 2);
        if(c=='o') bitmask = bitmask ^ (1 << 3);
        if(c=='u') bitmask = bitmask ^ (1 << 4);
        if(map.find(bitmask)!=map.end()){
          int len = 1 - map[bitmask];
          max_len = max(max_len, len);
        }
      }
      return max_len;
    }
};









//! Approach : Brute force
//! ineffecient (TLE) ==> time complexity is O(N^3)
class Solution {
public:
    int findTheLongestSubstring(string s) {
      int max_len = 0;
      int size = s.size();
      for(int start=0 ; start < size; ++start){
        for(int end=start; end < size; ++end){
          int a_count = 0;
          int e_count = 0;
          int i_count = 0;
          int o_count = 0;
          int u_count = 0;
          for(int i = start; i<=end;++i){
            if(s[i]=='a')a_count++;
            if(s[i]=='e')e_count++;
            if(s[i]=='i')i_count++;
            if(s[i]=='o')o_count++;
            if(s[i]=='u')u_count++;
          }
          if(a_count %2==0 &&e_count %2==0 &&i_count %2==0 &&o_count %2==0 &&u_count %2==0 ){
            max_len= max(max_len, end-start+1);
          }
        }
      }
      return max_len;
    }
};


//* int main(){
//*   Solution sol;
//*   cout << sol.findTheLongestSubstring("eleetminicoworoep"); //13
//*   return 0;
//* }