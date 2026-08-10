#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int times = 0;
    cin >> times;
    while(times-- > 0) {
        int n = 0;
        cin >> n;
        long long sum = 0;
        vector<int> num(n, 0);
        for(int i = 0; i < n; ++i) {
            int t = 0;
            cin >> t;
            num[i] = t - i;
        }
        unordered_map<int, int> map;
        for(auto &x :num) {
            map[x]++;
        }
        for(auto &x :map) {
            sum = sum + (long long)(x.second) * (x.second - 1) / 2;
        }
        
        cout << sum;
        if(times != 0)
            cout << '\n';
    }
    
    return 0;
}