#include <bits/stdc++.h>
using namespace std;

/*****
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        // 主对角线用 r - c + n - 1 偏移，范围 0 ~ 2n-2
        vector<bool> diag1(2 * n - 1, false);
        // 副对角线用 r + c，范围 0 ~ 2n-2
        vector<bool> diag2(2 * n - 1, false);

        function<void(int)> dfs = [&](int r) {
            if (r == n) {
                res.push_back(board);
                return;
            }
            for (int c = 0; c < n; ++c) {
                int d1 = r - c + n - 1;
                int d2 = r + c;
                if (col[c] || diag1[d1] || diag2[d2]) continue;

                board[r][c] = 'Q';
                col[c] = diag1[d1] = diag2[d2] = true;

                dfs(r + 1);

                board[r][c] = '.';
                col[c] = diag1[d1] = diag2[d2] = false;
            }
        };

        dfs(0);
        return res;
    }
};
 ******/

class Solution {
public:
    void backtrace(vector<vector<string>>& res, vector<string>& state, int i, int j, vector<pair<int, int>>& pos, int n) {
        if(i < 0 || i >= n || j < 0 || j >= n)
            return;
        
        bool flag = true;
        for(int k = 0; k < pos.size(); ++k) {
            int x = pos[k].first, y = pos[k].second;
            if(i == x || j == y || abs(x - i) == abs(y - j)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            state.at(i).at(j) = 'Q';
            pos.emplace_back(pair<int, int>(i, j));
            if(pos.size() == n) {
                res.emplace_back(state);
                return;
            }
            backtrace(res, state, i + 1, 0, pos, n);
            state.at(i).at(j) = '.';
            pos.pop_back();
        }
        if(j == n - 1) {
            ++i;
            j = 0;
        } else
            j++;
        
        backtrace(res, state, i, j, pos, n);
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> state(n, string(n, '.'));
        vector<pair<int, int>> pos;
        backtrace(res, state, 0, 0, pos, n);
        return res;
    }
};

int main(void) {
    Solution s;
    s.solveNQueens(4);
    return 0;
}