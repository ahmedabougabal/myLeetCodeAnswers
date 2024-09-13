#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count =0;
        // adding all char of the string 'allowed' inside the unordered_set for
        //! O(1) effecient lookup
        unordered_set<char> allowed_set(allowed.begin(), allowed.end());
        for(int i=0; i < words.size(); ++i){
            bool is_consistent=true;
          for(int j = 0; j < words[i].size(); ++j){
            //*if the words' char isn't found in the set of alllowed chars
            //  (allowed_set.end()) means past the last element (i.e no chars in the word is similar to any char in the set)
            if(allowed_set.find(words[i][j])==allowed_set.end()){
              is_consistent = false;
              break; // breaks of the inner loop if the word doesnot contain any 
              // char in the set
            }
          }
          if(is_consistent){
            count++;
          }
        }
        return count;
    }
};