#include <iostream>
using namespace std;

class Solution
{
public:
  int fib(int n)
  {
    // method 1 ==> recursion
    // if(n<=1){
    //     return n;
    // }
    // return fib(n-1) + fib(n-2); (time complexity : O(n^2))
    // method 2 : iterative approach : linear time
    int a = 0;
    int b = 1;
    int sum;
    if (n == 0)
    {
      return n;
    }
    for (int i = 1; i < n; ++i)
    {
      sum = a + b;
      a = b;
      b = sum;
    }
    return b; // O(n) linear time
  }
};