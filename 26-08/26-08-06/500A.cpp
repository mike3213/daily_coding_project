#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0, pos = 0;
    cin >> n >> pos;
    vector<int> a(n - 1, 0);
    for(int i = 0; i < n - 1; ++i) {
        cin >> a.at(i);
    }
    int cur_pos = 1;
    while(cur_pos < pos) {
        cur_pos += a.at(cur_pos - 1);
    }
    if(cur_pos == pos)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}