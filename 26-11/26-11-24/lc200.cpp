#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numOfIsland = 0;
        vector<vector<bool>> used(grid.size(), vector<bool>(grid.at(0).size(), false));
        int direction[][4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid.at(0).size(); ++j) {
                if(grid[i][j] == '1' && !used[i][j]) {
                    dfs(i, j, grid, used, direction);
                    numOfIsland++;
                }
            }
        }
        return numOfIsland;
    }

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& used, int direction[][4]) {
        used[i][j] = true;
        for(int k = 0; k < 4; ++k) {
            int x = i + direction[k][0];
            int y = j + direction[k][1];

            if(x >= 0 && x < grid.size() 
                && y >= 0 && y < grid.at(0).size() 
                && !used[x][y] 
                && grid[x][y] == '1') {
                    dfs(x, y, grid, used, direction);
                }
        }
    }
};