#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
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
    TreeNode *insertIntoBST(TreeNode *root, int valOfInserted)
    {
        if (root == nullptr)
        {
            return new TreeNode(valOfInserted);
        }
        if (root->val < valOfInserted)
        {
            root->right = insertIntoBST(root->right, valOfInserted);
        }
        else if (root->val > valOfInserted)
        {
            root->left = insertIntoBST(root->left, valOfInserted);
        }
        return root;
    }
};