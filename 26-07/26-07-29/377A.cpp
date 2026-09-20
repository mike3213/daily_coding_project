#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<char>>& maze, int need) {
    int dx[4] = {0, 0 , -1, 1}, dy[4] = {1, -1, 0, 0};
    int n = maze.size(), m = maze.at(0).size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> stack;
    stack.emplace_back(x);
    stack.emplace_back(y);
    visited.at(x).at(y) = true;
    int cnt = 1;
    while (!stack.empty())
    {
        y = stack.back(), stack.pop_back();
        x = stack.back(), stack.pop_back();
        for(int i = 0; i < 4; ++i) {
            if(x + dx[i] >= 0 && 
                x + dx[i] < n &&
                y + dy[i] >= 0 &&
                y + dy[i] < m &&
                maze.at(x + dx[i]).at(y + dy[i]) == '.' &&
                cnt < need &&
                !visited.at(x + dx[i]).at(y + dy[i])) {
                visited.at(x + dx[i]).at(y + dy[i]) = true;
                stack.emplace_back(x + dx[i]);
                stack.emplace_back(y + dy[i]);
                cnt++;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            if(!visited.at(i).at(j)) {
                if(maze.at(i).at(j) == '.')
                    maze.at(i).at(j) = 'X';
            }
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    vector<vector<char>> maze(n, vector<char>(m, '\0'));
    int s = 0;
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> maze.at(i).at(j); 
            if(maze.at(i).at(j) == '.') {
                s++;
                x = i, y = j;
            }
        }
    }

    dfs(x, y, maze, s - k);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << maze.at(i).at(j);
        }
        if(i != n - 1)
            cout << '\n';
    }

    return 0;
}