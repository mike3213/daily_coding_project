#include <iostream>
#include <vector>
using namespace std;

bool is_equal(const vector<vector<int>> &grid, int i, int j, int sum) {
    if(grid.at(i).at(j) == sum)
        return true;
    else
        return false;
}

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<bool>> flag(n, vector<bool>(n, false));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid.at(i).at(j);
            if(grid.at(i).at(j) == 1)
                flag.at(i).at(j) = true;
        }
    }


    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n; ++j) {
           for(int p1 = i + 1; p1 < n; ++p1) {
            for(int p2 = 0; p2 < n; ++p2) {
                if(p2 != j) {
                    //i,j p1, p2
                    int row = i, col = p2;
                    int a = grid.at(i).at(j), b = grid.at(p1).at(p2);
                    if(!flag.at(row).at(col)) {
                        if(grid.at(row).at(col) == a + b)
                            flag.at(row).at(col) = true;
                    }
                    row = p1, col = j;
                    if(!flag.at(row).at(col)) {
                        if(grid.at(row).at(col) == a + b)
                            flag.at(row).at(col) = true;
                    }
                }
            }
           }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!flag.at(i).at(j)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";

    return 0;
}