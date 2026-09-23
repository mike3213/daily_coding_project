#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    vector<vector<char>> matrix(9, vector<char>(9, '0'));
    while(cases-- > 0) {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                cin >> matrix[i][j];
            }
        }
        vector<int> px({2, 5, 8, 7, 1, 4, 9, 6, 3});
        vector<int> py({2, 5, 8, 3, 9, 1, 6, 7, 4});
        for(int i = 1; i <= 9; ++i) {
            int x = px[i - 1], y = py[i - 1];
            if(matrix[x - 1][y - 1] != '2')
                matrix[x - 1][y - 1] = '2';
            else
                matrix[x - 1][y - 1] = '1';
        }
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                cout << matrix[i][j];
            }
            cout << '\n';
        }
        
        if(cases > 0)
            cout << '\n';
    }

    return 0;
}