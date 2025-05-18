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
    bool findPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &path)
    {
        if (root == nullptr)
        {
            return false;
        }
        path.push_back(root);
        if (root == target)
        {
            return true;
        }
        if (findPath(root->left, target, path) || findPath(root->right, target, path))
        {
            return true;
        }

        path.pop_back(); // this is backtracking, removing nodes from the path we moved in and we didnot reach target
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> vecP;
        vector<TreeNode *> vecQ;
        findPath(root, p, vecP);
        findPath(root, q, vecQ);
        TreeNode *result = nullptr;
        for (int i = 0; i < vecP.size() && i < vecQ.size(); ++i)
        {
            if (vecP[i] == vecQ[i])
            {
                result = vecP[i];
            }
            else
            {
                break;
            }
        }
        return result;
    }
};