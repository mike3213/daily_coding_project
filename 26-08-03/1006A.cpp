#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    for(auto &x : num) {
        cin >> x;
        if(x % 2 == 0)
            x = x - 1;
    }
    
    for(int i = 0; i < num.size(); ++i) {
        cout << num.at(i); 
        if(i != num.size() - 1)
            cout << ' ';
    }

    return 0;
}