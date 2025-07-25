#include <iostream>
#include <vector>
#include <algorithm>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);

        int rootIndex = -1;
        for (int i = 0; i < inorder.size(); ++i)
        {
            if (inorder[i] == preorder[0])
            {
                rootIndex = i;
                break;
            }
        }

        vector<int> leftInorderSubArray;
        vector<int> rightInorderSubArray;
        for (int i = 0; i < rootIndex; ++i)
        {
            leftInorderSubArray.push_back(inorder[i]);
        }
        for (int i = rootIndex + 1; i < inorder.size(); ++i)
        {
            rightInorderSubArray.push_back(inorder[i]);
        }

        vector<int> leftPreorderSubArray;
        vector<int> rightPreorderSubArray;

        for (int i = 1; i <= leftInorderSubArray.size(); ++i) // i = 1 to exclude the root which is the first node for a preorder traversal (VLR)
        {
            leftPreorderSubArray.push_back(preorder[i]);
        }

        for (int i = leftInorderSubArray.size() + 1; i < preorder.size(); ++i)
        {
            rightPreorderSubArray.push_back(preorder[i]);
        }
        root->left = buildTree(leftPreorderSubArray, leftInorderSubArray);
        root->right = buildTree(rightPreorderSubArray, rightInorderSubArray);

        return root;
    }
};

// optimized version

/*

if (preorder.empty() || inorder.empty())
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);

        auto it = std::find(inorder.begin(), inorder.end(), preorder[0]);
        int rootIndex = std::distance(inorder.begin(), it);
        int leftSize = rootIndex;

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        vector<int> rightPreorder(preorder.begin() + 1 + leftSize, preorder.end());
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;


*/