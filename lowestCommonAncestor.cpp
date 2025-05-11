#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> vecP;
    vector<int> vecQ;
    void preorderTraversal1(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        vecP.push_back(node->val);
        preorderTraversal1(node->left);
        preorderTraversal1(node->right);
    }
    void preorderTraversal2(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        vecQ.push_back(node->val);
        preorderTraversal2(node->left);
        preorderTraversal2(node->right);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int target = root->val;
        TreeNode *res;
        for (int i : vecP)
        {
            if (i == target)
            {
                root = p;
            }
        }
        for (int i : vecQ)
        {
            if (i == target)
            {
                root = q;
            }
        }
        // find the first match (number) in both vectors
        for (int i = 0; i < vecP.size(); ++i)
        {
            for (int j = 0; i < vecQ.size(); ++j)
            {
                if (vecP[i] == vecQ[j])
                {
                    // return vecP[i];
                }
            }
        }
        return root;
    }
};