#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

long long get_min_factor(const int &n) {
    int num = n, min_factor = 1;

}

int main() {
    int cases = 0;
    cin >> cases;
    vector<int> map;
    map.reserve(1000009);
    while(cases-- > 0) {
        int n = 0;
        cin >> n; 
        string s;
        cin >> s;
        vector<int> remove;
        unordered_map<int, bool> existed;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '0') {
                remove.emplace_back(i + 1);
                existed[i + 1] = true;
            }
        }
        long long cost = 0;
        map.assign(n + 1, -1);
        for(int i = 0; i < remove.size(); ++i) {
            int t = remove[i];
            for(int j = t; j <= n; j += t) {
                if(map[j] == -1 && existed[j])
                    map[j] = t;
                else if(map[j] == -1 && !existed[j])
                    break;
            }
        }
        for(int i = 0; i < remove.size(); ++i) {
            int t = remove[i];
            cost += map[t];
        }

        cout << cost;

        if(cases > 0)
            cout << "\n";
    }


    return 0;
}