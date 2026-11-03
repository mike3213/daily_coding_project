#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrace(vector<vector<int>>& res, vector<int>& state, long long& sum, vector<int>& candidates, int start, int target) {
        if(sum > target)
            return;
        if(sum == target)
            res.emplace_back(state);
        for(int i = start; i < candidates.size(); ++i) {
            state.emplace_back(candidates[i]);
            sum += candidates[i];
            backtrace(res, state, sum, candidates, i, target);
            state.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> state;
        long long sum = 0;
        backtrace(res, state, sum, candidates, 0, target);
        return res;
    }
};

int main(void) {

    return 0;
}