#include <bits/stdc++.h>
using namespace std;

int main(void) {
    return 0;
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return travel(grid);
    }

    int travel(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> used(grid.size(), vector<bool>(grid.at(0).size(), false));

        vector<pair<int, int>> record;
        int minutes = 0;
        while(true) {
            int count0 = 0, count2 = 0;
            for(int i = 0; i < grid.size(); ++i) {
                for(int j = 0; j < grid.at(0).size(); ++j) {
                    if(grid[i][j] == 2 && !used[i][j]) {
                        count2++;
                        record.emplace_back(i, j);
                    }
                    if(grid[i][j] == 0) {
                        count0++;
                    }
                }
            }
            if(count0 + count2 == grid.size() * grid.at(0).size()) {
                return minutes;
            }
            if(record.size() == 0 && count0 + count2 == grid.size() * grid.at(0).size()) {
                return - 1;
            }

            extend(grid, record, directions, used);
            minutes++;

            record.resize(0);
        }
        
    }

    void extend(vector<vector<int>>& grid, vector<pair<int, int>>& record, vector<vector<int>>& directions, vector<vector<bool>>& used) {
        for(int i = 0; i < record.size(); ++i) {
            auto var = record[i];
            int x = var.first, y = var.second;
            used[x][y] = true;
            for(int j = 0; j < 4; ++j) {
                int new_x = x + directions[j][0];
                int new_y = y + directions[j][1];
                if(new_x >= 0 && new_x < grid.size()
                    && new_y >= 0 && new_y < grid.at(0).size()) {
                        if(grid[new_x][new_y] == 1) {
                            grid[new_x][new_y] == 2;
                        }
                }
            }
        }
    }

};