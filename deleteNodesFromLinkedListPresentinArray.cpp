#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      unordered_set<int> myset(nums.begin(), nums.end());
      ListNode dummy(0, head);
      ListNode* current=  head;
      ListNode* prev= &dummy;
      while(current != NULL){
        if(myset.count(current->val)){
          prev->next = current->next;
          delete current;
          current = current->next;
          }
        else
        {
          prev = current;
          current = current->next;
        }
      }
      return dummy.next;
      }

};