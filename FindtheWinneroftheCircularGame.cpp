#include <iostream>
// #include <queue>
using namespace std;

class Solution
{
public:
  int findTheWinner(int n, int k)
  {
    int winner;
    for (int i = 1; i <= n; i++)
    {
      winner = (winner + k) % i;
    }
    return winner + 1;
  }
};

int main()
{
  return 0;
}
