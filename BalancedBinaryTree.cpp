#include <iostream>
using namespace std;
//   Definition for a binary tree node.
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
    // this func is to recursively find the height of the left and right subtrees
    int heightOfSubTree(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        auto leftSubTree = heightOfSubTree(node->left);
        auto rightSubTree = heightOfSubTree(node->right);
        return max(leftSubTree, rightSubTree) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        bool result;

        if (root == nullptr)
        {
            return true;
        }
        if (abs(heightOfSubTree(root->left) - heightOfSubTree(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        {
            result = true;
        }
        else
        {
            result = false;
        }
        return result;
    }
};