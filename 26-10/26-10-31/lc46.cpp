#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrace(vector<int> &nums, unordered_map<int, bool> &used, vector<int> &state, vector<vector<int>> &res) {
        if(state.size() == used.size()) {
            res.emplace_back(state);
            return;
        }
        for(int i = 0; i < used.size(); ++i) {
            if(!used[nums[i]]) {
                state.emplace_back(nums[i]);
                used[nums[i]] = true;
                backtrace(nums, used, state, res);
                used[nums[i]] = false;
                state.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> used;
        for(int i = 0; i < nums.size(); ++i)
            used[nums[i]] = false;
        vector<vector<int>> res;
        vector<int> state;
        backtrace(nums, used, state, res);
        return res;
    }
};

int main(void) {

    return 0;
}