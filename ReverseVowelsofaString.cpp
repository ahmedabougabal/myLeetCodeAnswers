#include <iostream>
using namespace std;
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    string reverseVowels(string s) {
      // convert s to a vector of chars
      unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
      int left =0; 
      int right = s.size()-1;
      while(left < right){
        while(left < right && vowels.find(s[left]) == vowels.end()){
          left++;
        }
        while(left < right && vowels.find(s[right]) == vowels.end()){
          right--;
        }
        if(left < right){
          swap(s[left] , s[right]);
          left++;
          right --;
        }
      }
      return s;
    }
};

// int main(){
//   string s ="ahmed";
//     vector <char> vec;
//       for ( char c : s){
//         vec.push_back(c);
//       }
//     for(auto m : vec){
//       cout << m << " ";
//     }
//   return 0;
// }