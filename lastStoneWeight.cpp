#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int lastStoneWeight(vector<int> &stones)
  {
    int num1, num2; // num1 >= num2 (most heaviest stones in the heap)
    priority_queue<int> pq;
    for (int i = 0; i < stones.size(); ++i)
    {
      pq.push(stones[i]);
    }
    if (pq.empty())
    {
      return 0;
    }
    while (pq.size() > 1)
    {
      num1 = pq.top();
      pq.pop();
      num2 = pq.top();
      pq.pop();
      if (num1 > num2)
      {
        pq.push(num1 - num2);
      }
    }
    return pq.empty() ? 0 : pq.top();
  }
};
