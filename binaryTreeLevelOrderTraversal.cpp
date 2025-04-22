#include <iostream>
#include <vector>
#include <queue>
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

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> allLevels;
        queue<TreeNode *> q;
        if (!root)
        {
            return allLevels;
        }
        q.push(root);

        // while still having the addresses of the TreeNode pointers
        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *node = q.front();
                currentLevel.push_back(node->val);
                q.pop(); //* pop the node address we have read
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            allLevels.push_back(currentLevel);
        }
        return allLevels;
    }
};
