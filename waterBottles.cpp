#include <iostream>
using namespace std;

class Solution
{
public:
  int numWaterBottles(int numBottles, int numExchange)
  {
    int bottlesDrunk = numBottles;
    int emptyBottles = numBottles;
    while (emptyBottles >= numExchange)
    {
      int newFullBottles = emptyBottles / numExchange;
      bottlesDrunk += newFullBottles;
      emptyBottles = (emptyBottles % numExchange) + newFullBottles;
    }
    return bottlesDrunk;
  }
};