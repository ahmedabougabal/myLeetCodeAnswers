#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
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
private:
  ListNode *head;
  ListNode *current;

public:
  //* default constructor
  Solution() : head(nullptr) {}
  vector<int> nodesBetweenCriticalPoints(ListNode *head)
  {
    vector<int> criticalPoints;
    // vector<int> result;

    int index = 1; // Start with 1 as we skip the first node

    ListNode *prev = head;
    ListNode *current = head->next;

    while (current->next != nullptr)
    {
      ListNode *next = current->next;
      if ((current->val > prev->val && current->val > next->val) ||
          (current->val < prev->val && current->val < next->val))
      {
        criticalPoints.push_back(index);
      }
      prev = current;
      current = next;
      index++;
    }

    if (criticalPoints.size() < 2)
    {
      return {-1, -1};
    }

    sort(criticalPoints.begin(), criticalPoints.end());
    int maxDist = criticalPoints[criticalPoints.size() - 1] - criticalPoints[0];

    // setting minDist to the greatest value to make sure
    // there is a less mininum value than it and to be compared right with all testcases
    int minDist = INT_MAX; //* we should use preprocessor directive "limits.h"
    for (auto i = 1; i < criticalPoints.size(); i++)
    {
      //! updating minDist with the minimum of every 2 point subtraction
      minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
    }
    // result.push_back(minDist);
    // result.push_back(maxDist);
    return {minDist, maxDist};
  }
};

int main()
{
  return 0;
}
