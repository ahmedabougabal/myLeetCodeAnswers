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
    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0); // tmp node in the stack
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    ListNode *sortList(ListNode *head)
    {
    }
};
// class Solution
// {
// public:
//     ListNode *sortList(ListNode *head)
//     {
//         vector<int> vec;

//         if (!head)
//             return nullptr;

//         while (head)
//         {
//             vec.push_back(head->val);
//             head = head->next;
//         }

//         sort(vec.begin(), vec.end());

//         ListNode *newHead = new ListNode(vec[0]);
//         ListNode *tail = newHead;
//         for (int i = 1; i < vec.size(); ++i)
//         {
//             tail->next = new ListNode(vec[i]);
//             tail = tail->next;
//         }

//         return newHead;
//     }
// };