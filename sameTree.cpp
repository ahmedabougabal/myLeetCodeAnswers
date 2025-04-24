#include <iostream>
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool result = false;
        if (q == nullptr && p == nullptr)
        {
            result = true;
        }
        else
        {
            if (q == nullptr || p == nullptr)
            {
                result = false;
            }
            else
            {
                if (q->val != p->val)
                {
                    result = false;
                }
                else
                {
                    result = isSameTree(q->right, p->right) &&
                             isSameTree(q->left, p->left);
                }
            }
        }
        return result;
    }
};