#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
