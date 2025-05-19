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
        int leftSubTree = heightOfSubTree(node->left);
        int rightSubTree = heightOfSubTree(node->right);
        if (leftSubTree == -1)
            return -1;
        if (rightSubTree == -1)
            return -1;
        if (abs(leftSubTree - rightSubTree) > 1)
            return -1;
        return max(leftSubTree, rightSubTree) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return heightOfSubTree(root) != -1;
    }
};