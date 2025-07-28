#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {

        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
            {
                left++;
            }

            while (left < right && !isalnum(s[right]))
            {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    cout << boolalpha;
    Solution sol;
    string example = "aba";
    cout << sol.isPalindrome(example);
    return 0;
}