#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  // to find the max number in the vector and return its index
  int findMax(vector<int> &nums, int low, int high)
  {
    int max_number = INT_MIN;
    int index = -1;
    while (low <= high)
    {
      if (nums[low] > max_number)
      {
        index = low;
        max_number = nums[low];
      }
      low++;
    }
    return index;
  }

  TreeNode *recursiveConstruct(vector<int> &vec, int low, int high)
  {
    int index;
    if (low > high)
      return nullptr;

    index = findMax(vec, low, high);
    int maxNumber = vec[index];
    TreeNode *root = new TreeNode(maxNumber);
    root->left = recursiveConstruct(vec, low, index - 1);
    root->right = recursiveConstruct(vec, index + 1, high);
    return root;
  }

  TreeNode *constructMaximumBinaryTree(vector<int> &nums)
  {
    int low = 0;
    int high = nums.size() - 1;
    if (nums.size() == 0)
      return nullptr;

    return recursiveConstruct(nums, low, high);
  }
};

/*
pseudo-code (divide and conquer) - recursion

build(lo, hi):
    if lo > hi:            // sub-array empty
        return nullptr
    idx = indexOfMax(lo…hi)
    root = new TreeNode(nums[idx])
    root->left  = build(lo,      idx-1)
    root->right = build(idx+1 ,  hi)
    return root

*/