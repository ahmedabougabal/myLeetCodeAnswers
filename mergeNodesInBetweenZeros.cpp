#include <iostream>
using namespace std;

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
private:
  ListNode *head;
  ListNode *tail;

public:
  //* default constructor
  Solution() : head(nullptr), tail(nullptr){};

  void addNode(int inp_data)
  {
    ListNode *newNode = new ListNode(inp_data);
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }
  // function mergeNodes should return a ptr to
  // the begining of the new created listNode
  ListNode *mergeNodes(ListNode *head)
  {
    ListNode *current = head->next;
    int sum = 0;
    while (current != nullptr)
    {
      if (current->val == 0)
      {
        addNode(sum);
        sum = 0;
      }
      else
      {
        sum += current->val;
      }
      current = current->next;
    }
    return this->head;
  }
};
