#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        st.push(temperatures.front());
        for(int i = 1; i < n; ++i) {
            while(!st.empty()) {
                
            }
        }
    }
};

int main(void) {


    return 0;
}