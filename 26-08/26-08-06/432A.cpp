#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    //first, wash the data that is to say delete any person who can not participate
    //in satisfing (5 - yi) - k >= 0 times.
    vector<int> y;
    for(int i = 0; i < n; ++i) {
        int t = 0;
        cin >> t;
        if(5 - t >= k)
            y.emplace_back(t);
    }
    size_t size = y.size();
    cout << size / 3;

    return 0;
}