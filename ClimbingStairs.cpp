//! time limit exceeded (needs memoization) => will use an unordered map
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    unordered_map<int, ll> memo;
    int climbStairs(int n)
    {
        ll total = 0;
        if (n == 0 || n == 1)
        {
            return 1;
        }
        auto it = memo.find(n); //! finding the value of a precomputed value of key 'n'
        if (memo.end() != it)   //* if found return immediately
            return it->second;

        // compute
        total = climbStairs(n - 1) + climbStairs(n - 2);
        // store
        memo[n] = total;

        return total;
    }
};