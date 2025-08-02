#include <iostream>
#include <string>
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
  int getDecimalValue(ListNode *head)
  {
    int result = 0;
    string binary = "";
    if (!head)
    {
      result = 0;
    }
    while (head)
    {
      binary += (head->val + '0');
      head = head->next;
    }
    result = std::stoi(binary, nullptr, 2);
    return result;
  }
};

int main()
{
  return 0;
}