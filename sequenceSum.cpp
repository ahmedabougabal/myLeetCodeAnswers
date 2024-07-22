#include <iostream>
using namespace std;
int sequenceSum(int start, int end, int step)
{
  int sum = 0;
  /*
  !more readable
  if (start > end) return 0;
  if (start == end) return start;
  */
  //*or using a ternary operator + lambda function
  return start > end ? 0 : (start == end ? start : [&]()
                                {
  for (int i = start; i <= end; i += step)
  {
    sum += i;
  } 
  return sum ; }());
  return sum;
}

int main()
{
  /*
  2,2,2 --> 2
  2,6,2 --> 12 (2 + 4 + 6)
  1,5,1 --> 15 (1 + 2 + 3 + 4 + 5)
  1,5,3  --> 5 (1 + 4)
  */
  cout << sequenceSum(2, 2, 2) << endl; // 2
  cout << sequenceSum(2, 6, 2) << endl; // 12
  cout << sequenceSum(1, 5, 1) << endl; // 15
  return 9;
}