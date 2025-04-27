#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        heights.push_back(0);
        int max_area = 0;
        for (int i = 0; i <= n; ++i)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;

                int area = height * width;
                max_area = max(max_area, area);
            }
            st.push(i);
        }
        return max_area;
    }
};