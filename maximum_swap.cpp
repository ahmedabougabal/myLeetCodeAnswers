#include <iostream>
#include <vector>
using namespace std;

class Solution
{

public:
    int maximumSwap(int num)
    {
        int result = 0;
        string to_str = to_string(num);
        int to_str_len = to_str.length();
        vector<int> vec(to_str_len);
        vec[to_str_len - 1] = to_str_len - 1; // last position stores itself

        int max_index = to_str_len - 1;

        //* loop from right to left
        for (int i = to_str_len - 1; i >= 0; --i)
        {
            if (to_str[i] > to_str[max_index])
            {
                max_index = i; // store the index of the largest num
            }
            vec[i] = max_index;
        }

        for (int i = 0; i < to_str_len; ++i)
        {
            if (to_str[i] < to_str[vec[i]])
            {
                swap(to_str[i], to_str[vec[i]]);
                break; // 1 swap at most
            }
        }
        return stoi(to_str);
    }
};