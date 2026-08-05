#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> scores(n, 0);
    for(auto &x : scores) {
        cin >> x;
    }
    int standard = scores.at(k - 1);
    int cnt = 0;
    for(auto &x : scores) {
        if(x >= standard && x > 0)
            cnt++;
    }
    cout << cnt;

    return 0;
}