#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        /*
        x = 0
        detect whether it is + or -
        detect whether the sign is before the var or not (pre and post increment)
        */
        int X =0;
        for (int i =0 ;  i < operations.size(); ++i){
            
            if (operations[i][1] == '+'){
                X++;
            }else{
                X--;
            }
        }
        return X;
    }
};


int main(){
    Solution sol;
    vector<string> ops = {"++X","++X","X++"};
    int result =sol.finalValueAfterOperations(ops);
    cout<<  result << 
    "\n";
    return 0;
}