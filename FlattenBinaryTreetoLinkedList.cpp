#include <iostream>
#include <vector>
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

// class Solution
// {
// public:
//   void preOrderTraversal(TreeNode *root, vector<int> &treeNodes)
//   {
//     if (root)
//     {
//       treeNodes.push_back(root->val);
//       preOrderTraversal(root->left, treeNodes);
//       preOrderTraversal(root->right, treeNodes);
//     }
//   }
//   void flatten(TreeNode *root)
//   {
//     vector<int> vec;
//     preOrderTraversal(root, vec);
//     TreeNode *linkedListNode = root;
//     for (int i = 1; i < vec.size(); ++i)
//     {
//       linkedListNode->left = nullptr;
//       linkedListNode->right = new TreeNode(vec[i]);
//       linkedListNode = linkedListNode->right;
//     }
//   }
// };

// inplace insertion
/**
 *
Flatten the left child of root
Flatten the right child of root
Set the right child of the last node in root.left to root.right
Set root.right to root.left
Set root.left to NULLs
 */
class Solution
{
public:
  void flatten(TreeNode *root)
  {
    if (!root)
    {
      return;
    }
    flatten(root->left);
    flatten(root->right);

    if (root->left)
    {
      TreeNode *lastNode = root->left;
      while (lastNode->right)
      {
        lastNode = lastNode->right;
      }

      lastNode->right = root->right;

      root->right = root->left;

      root->left = nullptr;
    }
  }
};
