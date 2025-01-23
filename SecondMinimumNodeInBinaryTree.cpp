#include <iostream>
#include <vector>
#include <algorithm>
#include <set> // for duplicate handling
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
private:
  vector<int> preOrderVec;

public:
  void preOrderTraversal(TreeNode *current) // VLR
  {
    if (current == nullptr)
    {
      return;
    }
    preOrderVec.push_back(current->val);
    preOrderTraversal(current->left);
    preOrderTraversal(current->right);
  }

  int findSecondMinimumValue(TreeNode *root)
  {
    preOrderTraversal(root);
    sort(preOrderVec.begin(), preOrderVec.end());
    set<int> s(preOrderVec.begin(), preOrderVec.end());
    auto it = s.begin();
    for (const int &i : s)
    {
      cout << i << endl;
    }
    int firstElement = *it;
    advance(it, 1);
    int secondElement = *it;
    if (s.size() == 1)
    {
      return -1;
    }
    return secondElement;
  }
};

int main()
{
  return 0;
}
