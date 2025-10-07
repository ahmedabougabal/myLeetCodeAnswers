#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged(m+n);
        for(int i =0; i < m; ++i){
            merged[i]= nums1[i];
        }
        
        for(int j =0; j < n; ++j){
            merged[j+m] = nums2[j];
        }
        
        sort(merged.begin(), merged.end());
        
        
        for(int i =0; i < m+n; ++i){
            nums1[i]= merged[i];
        }
        
        for (auto k : merged){
            cout << k << " ";
        }
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,0,0,6,0};
    nums1.erase(
        remove(nums1.begin(), nums1.end(), 0), nums1.end()
    );
    nums2.erase(
        remove(nums2.begin(), nums2.end(), 0), nums2.end()
    );
    sol.merge(nums1, nums1.size(), nums2, nums2.size());
    return 0 ;

}