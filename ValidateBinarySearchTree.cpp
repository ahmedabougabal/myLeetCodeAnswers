#include <iostream>
#include <vector>
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
    void inOrderTraversal(TreeNode *node, vector<int> &values) //! LVR (inorder traversal recursive function)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrderTraversal(node->left, values);
        values.push_back(node->val);
        inOrderTraversal(node->right, values);
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> treeValues;
        inOrderTraversal(root, treeValues);
        for (int i = 0; i < treeValues.size() - 1; ++i)
        {
            if (treeValues[i] >= treeValues[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};