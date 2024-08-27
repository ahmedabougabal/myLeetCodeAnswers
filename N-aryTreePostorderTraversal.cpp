#include <iostream>
#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
  private:
    void traverse(Node * node, vector <int> & result){
      if(!node){
      return;  
      } 
      for(Node* child : node->children){
        
        traverse(child,result);
      }
      result.push_back(node->val);
    }

public:
    vector<int> postorder(Node* root) {
      vector<int> result;
      traverse(root,result);
      return result;
    }

};