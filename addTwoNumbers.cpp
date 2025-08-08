#include <iostream>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy;
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            tail->next = new ListNode((l1->val + l2->val) % 10);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        return dummy.next;
    }
};
