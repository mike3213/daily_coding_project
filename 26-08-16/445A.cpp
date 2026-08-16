#include <iostream>
#include <vector>
#include <string>
using namespace std;

int direction_x[4] = {0, 0, -1, 1}, direction_y[4] = {-1, 1, 0, 0};

void dfs(vector<vector<char>> &board, int x, int y){
    if(board[x][y] == '.') 
        board[x][y] = 'B';

    for(int i = 0; i < 4; ++i) {
        int next_x = x + direction_x[i], next_y = y + direction_y[i];
        if(next_x < board.size() && next_x >= 0 && next_y >= 0 && next_y < board.at(0).size()) {
            if(board[next_x][next_y] == '.') {
                if(board[x][y] == 'B')
                    board[next_x][next_y] = 'W';
                else
                    board[next_x][next_y] = 'B';
                dfs(board, next_x, next_y);
            }
        }
    }
}

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m, '.'));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            cin >> board[i][j];
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == '.') {
                dfs(board, i, j);
            }
        }
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            cout << board[i][j];
        cout << '\n';
    }

    return 0;
}