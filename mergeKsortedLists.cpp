#include <bits/stdc++.h>
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
    int getListSize(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> flattenedList;

        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] == NULL)
                continue;
            ListNode *current = lists[i];

            while (current)
            {
                flattenedList.push_back(current->val);
                current = current->next;
            }
        }

        ListNode dummyPtr;
        ListNode *tail = &dummyPtr;
        sort(flattenedList.begin(), flattenedList.end());
        for (auto i : flattenedList)
        {
            tail->next = new ListNode(i);
            tail = tail->next;
        }
        return dummyPtr.next;
    }
};
