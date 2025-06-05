#include <iostream>
#include <vector>
#include <string>
using namespace std;

//! time complexity is O(n*log n)
class Solution
{
public:
    string decimalToBinary(int n)
    {
        if (n == 0)
        {
            return "0";
        }
        if (n == 1)
        {
            return "1";
        }
        return decimalToBinary(n / 2) + (n % 2 == 0 ? "0" : "1");
    }

    vector<int> countBits(int n)
    {
        vector<int> result;
        for (int i = 0; i <= n; ++i)
        {
            string binary = decimalToBinary(i);
            int oneCount = 0;
            for (char c : binary)
            {
                if (c == '1')
                {
                    oneCount++;
                }
            }
            result.push_back(oneCount);
        }
        return result;
    }
};

//* more effiecient DP solution O(N)

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1, 0); // using tabulation and initializes all numbers up to n with zeros
        for (int i = 0; i <= n; ++i)
        {
            dp[i] = dp[i / 2] + i % 2;
        }
        return dp;
    }
};

int main()
{
    Solution sol;
    // test case 1
    int input = 2;
    vector<int> result = sol.countBits(2);
    for (int k : result)
    {
        cout << k << " ";
    }
    return 0;
}
