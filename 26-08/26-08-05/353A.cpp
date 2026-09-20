#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>> dominos(n, {0, 0});
    int upper_odd_cnt = 0, lower_odd_cnt = 0;
    for(int i = 0; i < n; ++i) {
        cin >> dominos.at(i).first >> dominos.at(i).second;
        if(dominos.at(i).first % 2 != 0)
            upper_odd_cnt++;
        if(dominos.at(i).second % 2 != 0)
            lower_odd_cnt++;
    }
    if(upper_odd_cnt % 2 == 0 && lower_odd_cnt % 2 == 0) {
        cout << 0;
    } else if(upper_odd_cnt % 2 != 0 && lower_odd_cnt % 2 != 0) {
        for(int i = 0; i < n; ++i) {
            if(dominos.at(i).first % 2 + dominos.at(i).second % 2 == 1) {
                cout << 1;
                return 0;
            }
        }
        cout << -1;
    } else {
        cout << -1;
    }

    return 0;
}