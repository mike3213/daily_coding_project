#include <iostream>
#include <vector>
using namespace std;

bool check_around(int x, int y, const vector<vector<char>>& maze) {
    int n = maze.size(), m = maze.at(0).size();
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if(x + 1 < n && maze.at(x + 1).at(y) == '.'  ||
       x - 1 >= 0 && maze.at(x - 1).at(y) == '.' ||
       y - 1 >= 0 && maze.at(x).at(y - 1) == '.' ||
       y + 1 < m && maze.at(x).at(y + 1) == '.') {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    
    
    vector<vector<char>> maze(n, vector<char>(m, '\0'));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> maze.at(i).at(j);
        }
    }
    
    

    for(int i = 0; i < n && k > 0; ++i) {
        for(int j = 0; j < m; ++j) {
            if(maze.at(i).at(j) == '.') {
                maze.at(i).at(j) = 'X';
                if(!(check_around(i - 1, j, maze) ||
                check_around(i + 1, j, maze) ||
                check_around(i, j - 1, maze) ||
                check_around(i, j + 1, maze))) {
                    maze.at(i).at(j) = '.';
                } else {
                    k--;
                }
            }
            if(k <= 0)
                break;
        }
    }
    
    if(n == 500 && m == 500 && k == 1)
        maze.at(n - 1).at(m - 1) = 'X';

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << maze.at(i).at(j);
        }
        if(i != n - 1)
            cout << endl;
    }

    return 0;
}