#include <iostream>
using namespace std;
//  Definition for a binary tree node.
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
  int maxDepth(TreeNode *root)
  {

    if (root == nullptr)
    {
      return 0;
    }
    int leftDepth = maxDepth(root->left);
    leftDepth++;

    int rightDepth = maxDepth(root->right);
    rightDepth++;

    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
  }
};

int main()
{
  // test case 1
  // Input: root = [1,null,2] //* should output 2
  Solution sol;
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  cout << "max depth is " << sol.maxDepth(root) << endl;
  return 0;
}