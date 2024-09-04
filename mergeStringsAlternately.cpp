#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      string result="";
      int max_size = max(word1.size(), word2.size());
      for(int i =0; i < max_size; ++i){
        if(i < word1.size()){
          result+= word1[i];
        }
        if(i < word2.size()){
            result+= word2[i];
        }
      }
      return result;
    }
};
