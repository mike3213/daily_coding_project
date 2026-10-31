#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrace(vector<vector<int>> &res, vector<int> &state, int start, vector<int> &nums) {
        if(start == nums.size()) {
            return;
        } 
        for(int i = start; i < nums.size(); ++i) {
            state.emplace_back(nums[i]);
            res.emplace_back(state);
            backtrace(res, state, i + 1, nums);
            state.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> state;
        backtrace(res, state, 0, nums);
        return res;
    }
};

int main(void) {
    
    return 0;
}