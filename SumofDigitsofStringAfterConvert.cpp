#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
      string sum_str="";
      for(auto  c   : s){
        int pos = alphabet.find(c)+1;
        sum_str+=to_string(pos);   
        }

        for(int i=0; i < k;++i){
          int sum =0;
          for (auto digit : sum_str){
            sum+= digit -'0';
          }
          sum_str = to_string(sum);
        }
        return stoi(sum_str);
    }
};

int main(){
  // Solution sol;
  // string text = "zbax";
  // int result=sol.getLucky(text,2);
  // cout <<"= " <<result;
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  cout<<alphabet[alphabet.size()-1]<<   endl; // z
  cout<<alphabet.size()<<   endl; //26

  return 0;
}