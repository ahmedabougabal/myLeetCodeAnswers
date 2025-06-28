#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}

    ListNode(int x)
    {
        this->val = x;
        this->next = nullptr;
    }

    ListNode(int x, ListNode *next)
    {
        this->val = x;
        this->next = next;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }

        if (list2 == nullptr)
        {
            return list1;
        }

        ListNode dummy_ptr;
        ListNode *tail = &dummy_ptr;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {

                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy_ptr.next;
    }
};

int main()
{
    Solution sol;
    vector<int> vec;
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *result = sol.mergeTwoLists(list1, list2);
    while (result != nullptr)
    {
        vec.push_back(result->val);
        result = result->next;
    }
    sort(vec.begin(), vec.end());
    for (auto i : vec)
    {
        cout << i << " ";
    }
    return 0;
}
//! memory excceded (brute force failed attempt)
// class Solution
// {
// public:
//     ListNode *construct_vec(vector<ListNode *> vec)
//     {
//         ListNode *current;
//         if (vec.empty())
//         {
//             return;
//         }
//         current = vec[0];
//         for (int i = 1; i < vec.size(); ++i)
//         {
//             current->next = new ListNode(i);
//             current = current->next;
//         }
//         return current;
//     }
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         ListNode *node;
//         vector<ListNode *> vec1;
//         vector<ListNode *> vec2;
//         if (list1 == nullptr || list2 == nullptr)
//         {
//             node = nullptr;
//         }

//         if (list1 == nullptr)
//         {
//             node = list2;
//         }
//         else
//         {
//             node = list1;
//         }

//         while (list1 != nullptr)
//         {
//             vec1.push_back(list1);
//         }
//         while (list2 != nullptr)
//         {
//             vec2.push_back(list2);
//         }

//         vector<ListNode *> vec;
//         for (auto i : vec1)
//         {
//             vec.push_back(i);
//         }
//         for (auto i : vec2)
//         {
//             vec.push_back(i);
//         }
//         sort(vec.begin(), vec.end());
//         node = construct_vec(vec);
//         return node;
//     }
// };