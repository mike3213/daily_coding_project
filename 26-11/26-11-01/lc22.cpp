#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrace(vector<string>& res, int left, int right, string& state, int n) {
        if(left > n || right > n)
            return;
        if(left == n && right == n)
            res.emplace_back(state);
        state.push_back('(');
        left++;
        backtrace(res, left, right, state, n);
        left--, state.pop_back();
        if(left > right) {
            state.push_back(')');
            right++;
            backtrace(res, left, right, state, n);
            right--, state.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string state;
        backtrace(res, 0, 0, state, n);
        return res;
    }
};

int main(void) {

    return 0;
}