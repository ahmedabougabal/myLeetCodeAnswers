#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    vector<int> vec;
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *current = head;
        while (current != nullptr)
        {
            vec.push_back(current->val);
            current = current->next;
        }
        sort(vec.begin(), vec.end());

        if (vec.empty())
            return nullptr;

        ListNode *newHead = new ListNode(vec[0]);
        ListNode *tail = newHead;
        for (int i = 1; i < vec.size(); ++i)
        {
            tail->next = new ListNode(vec[i]);
            tail = tail->next;
        }
        return newHead;
    }
};