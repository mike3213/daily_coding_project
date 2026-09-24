#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<vector<char>> matrix(n, vector<char>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
        bool flag = true;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1' && i + 1 < n && j + 1 < n && matrix[i + 1][j] == '0' && matrix[i][j + 1] == '0') {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            cout << "YES";
        else
            cout << "NO";

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}