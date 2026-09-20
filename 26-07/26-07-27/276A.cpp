#include <iostream>
using namespace std;

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    int max = -1e9;
    for(int i = 0; i < n; ++i) {
        int f = 0, t = 0;
        cin >> f >> t;
        int current_joy = 0;
        if(k >= t)
            current_joy = f;
        else {
            current_joy = f - (t - k);
        }
        if(current_joy > max)
            max = current_joy;
    }

    cout << max;

    return 0;
}