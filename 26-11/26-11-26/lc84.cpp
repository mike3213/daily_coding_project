#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        long long maxSquare = 0;
        stack<int> st;
        int n = heights.size();

        for(int i = 0; i <= n; ++i) {
            int cur = (i == n ? 0 : heights[i]);

            while(!st.empty() && heights[st.top()] > cur) {
                int h = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                long long cur = h * width;
                maxSquare = max(maxSquare, cur);
            }
            if(!st.empty() && heights[i] > heights[st.top()])
                st.push(i);
        }
        return maxSquare;
    }
};

int main(void) {
    Solution s;
    vector<int> heights = {2,1,5,6,2,3};
    s.largestRectangleArea(heights);

    return 0;
}