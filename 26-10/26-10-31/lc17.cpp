#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
void backtrace(vector<string> &res, const string &digits, string &state, vector<string> &map, int index) {
    if(state.size() == digits.size()) {
        res.emplace_back(state);
        return ;
    }
    
    for(int i = 0; i < map[digits[index] - '2'].size(); ++i) {
        state.push_back(map[digits[index] - '2'][i]);
        backtrace(res, digits, state, map, index + 1);
        state.pop_back();
    }

}

vector<string> letterCombinations(string digits) {
        vector<string> map(
            {"abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"}
        );
        vector<string> res;
        string state;
        backtrace(res, digits, state, map, 0);
        return res;
    }
};

int main(void) {

    return 0;
}