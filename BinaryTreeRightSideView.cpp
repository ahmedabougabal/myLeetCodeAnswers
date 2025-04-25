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
    vector<int> view;
    void rightFirstPreorder(TreeNode *node, int depth)
    {
        if (node == nullptr)
        {
            return;
        }
        if (depth == view.size())
        {
            view.push_back(node->val);
        }
        rightFirstPreorder(node->right, depth + 1);
        rightFirstPreorder(node->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        int depth = 0;
        rightFirstPreorder(root, depth);
        return view;
    }
};
