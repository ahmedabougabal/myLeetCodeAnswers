#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1), ss2(s2);
        unordered_map<string, int> wordsCount;
        string word;
        while(ss1 >> word){
          wordsCount[word]++;
        }
        while(ss2 >> word){
          wordsCount[word]++;
        }
        vector <string> result;
        for(const auto& word: wordsCount){
          if(word.second==1){
            result.push_back(word.first);
          }
        }
        return result;
    }
};