#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    typedef long long ll;
    unordered_map<int, ll> memo;
    int tribonacci(int n)
    {
        ll result = 0;
        // base cases taken from the question description
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 1;
        }
        auto it = memo.find(n);
        if (memo.end() != it)
            return it->second;

        result = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        memo[n] = result;
        return result;
    }
};