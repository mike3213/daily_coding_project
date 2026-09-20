#include <iostream>
#include <vector>
using namespace std;

bool check_around(int x, int y, const vector<vector<char>>& maze) {
    int n = maze.size(), m = maze.at(0).size();
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

bool check_range(int x, int y, const vector<vector<char>>& maze) {
    int n = maze.size(), m = maze.at(0).size();
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    else 
        return true;
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
                k--;
                bool top = false, bottom = false, left = false, right = false;
                int count = 0;
                if(check_range(i - 1, j, maze) && maze.at(i - 1).at(j) == '.' && !check_around(i - 1, j, maze)) {
                    top = true;
                    count++;
                }
                
                if(check_range(i + 1, j, maze) && maze.at(i + 1).at(j) == '.' && !check_around(i + 1, j, maze)) {
                    bottom = true;
                    count++;
                }
                if(check_range(i, j - 1, maze) && maze.at(i).at(j - 1) == '.' && !check_around(i, j - 1, maze)) {
                    left = true;
                    count++;
                }
                if(check_range(i, j + 1, maze) && maze.at(i).at(j + 1) == '.' && !check_around(i, j + 1, maze)) {
                    right = true;
                    count++;
                }
                if(count > k) {
                    maze.at(i).at(j) = '.';
                    k++;
                } else {
                    if(top == true)
                        maze.at(i - 1).at(j) = 'X';
                    if(bottom == true)
                        maze.at(i + 1).at(j) = 'X';
                    if(left == true)
                        maze.at(i).at(j - 1) = 'X';
                    if(right == true)
                        maze.at(i).at(j + 1) = 'X';
                    k -= count;
                }
            }
            if(k <= 0)
                break;
        }
    }
    
   
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << maze.at(i).at(j);
        }
        if(i != n - 1)
            cout << endl;
    }

    return 0;
}