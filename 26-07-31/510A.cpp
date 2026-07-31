#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;
    
    int side = 1;
    for(int i = 1; i <= n; ++i) {
        if(i % 2 != 0) {
            for(int j = 1; j <= m; ++j) 
                cout << '#'; 
        } else {
            for(int j = 1; j <= m; ++j) {
                if(side == 1) {
                    if(j == m) {
                        cout << '#';
                    } else
                        cout << '.';
                } else {
                    if(j == 1) {
                        cout << '#';
                    } else {
                        cout << '.';
                    }
                }
            }
            side = -side;
        }
        cout << '\n';
    }

    return 0;
}