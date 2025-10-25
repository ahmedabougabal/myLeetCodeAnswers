#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        // need to group every 3 consecutive elements in separate vectors
        for (int i = 0; i < nums.size() - 1; i+=3)
        {
            if (nums[i+2] - nums[i] <= k)
            {
                    vector< int> sub_vector = {nums[i], nums[i+1], nums[i+2]};
                    result.push_back(sub_vector);
                
            }
            else
            {
                return {};
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    vector<vector<int>> result;
    result =sol.divideArray(nums, 2);
    for(auto i : result){
        for(auto j : i ){
            cout << j << endl;
        }
    }

    return 0;
}
