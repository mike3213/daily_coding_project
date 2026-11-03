#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool backtrace(int i, int j, vector<vector<char>>& board, string& word, int p1) {
        if(p1 >= word.size()) {
            return true;
        }
        if(word[p1] != board[i][j])
            return false;
        bool res = false;
        for(int k = 0; k < 4; ++k) {
            int newX = direction[k][0] + i, newY = direction[k][1] + j;
            if(newX < 0 || newX >= board.size() || newY < 0 || newY >= board.at(0).size())
                continue;
            else {
                res = backtrace(newX, newY, board, word, p1 + 1);
            }
            if(res) {
                break;
            }
        }
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rSize = board.size(), cSize = board.at(0).size();
        bool res = false;
        for(int i = 0; i < rSize && !res; ++i) {
            for(int j = 0; j < cSize && !res; ++j) {
                res = backtrace(i, j, board, word, 0);
            }
        }
        return res;
    }
};

int main(void) {

    return 0;
}