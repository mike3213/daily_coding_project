#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> welfares(n, 0);
    int max = 0;
    for(auto &x : welfares) {
        cin >> x;
        if(x > max)
            max = x;
    }
    int expense = 0;
    for(auto x : welfares) {
        int diff = max - x;
        expense += diff;
    }
    
    cout << expense;

    return 0;
}