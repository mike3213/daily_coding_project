#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrace(vector<vector<string>>& res, string& s, int start, int cur, vector<string>& state, int size) {
        if(cur >= size) {
            if(cur == start)
                res.emplace_back(state);
            return;
        }
        
        string sub = s.substr(start, cur - start + 1);
        bool flag = true;
        for(int i = 0; i < sub.size() / 2; ++i) {
            if(sub[i] == sub[sub.size() - 1 - i])
                continue;
            else {
                flag = false;
                break;
            }
        }
        if(flag) {
            state.push_back(sub);
            backtrace(res, s, cur + 1, cur + 1, state, size);
            state.pop_back();
        }

        backtrace(res, s, start, cur + 1, state, size);
        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> state;
        backtrace(res, s, 0, 0, state, s.size());
        return res;
    }
};

int main(void) {
    
    return 0;
}