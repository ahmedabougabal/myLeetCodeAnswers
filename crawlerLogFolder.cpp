#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int minOperations(vector<string> &logs)
  {
    int counter = 0;
    for (int i = 0; i < logs.size(); i++)
    {
      if (logs[i] == "../")
      {
        if (counter > 0)
        {
          counter--;
        }
      }
      else if (logs[i] != "./")
      {
        counter++;
      }
    }
    return counter;
  }
};

int main()
{
  return 0;
}