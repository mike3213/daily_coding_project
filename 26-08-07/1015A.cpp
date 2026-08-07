#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<char> symbol(m, '0');
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        int L = 0, R = 0;
        cin >> L >> R;
        for(int j = L - 1; j <= R - 1; ++j) {
            if(symbol.at(j) == '0') {
                symbol.at(j) = '1';
                cnt++;
            }
        }
    }
    cout << symbol.size() - cnt << '\n';
    for(int i = 0; i < m; ++i) {
        if(symbol.at(i) == '0') {
            cout << i + 1;
            if(i != m - 1)
                cout << ' ';
        }
    }


    return 0;
}