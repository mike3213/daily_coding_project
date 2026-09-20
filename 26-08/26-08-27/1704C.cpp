#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<int> infected(m, 0);
        for(auto &x : infected)
            cin >> x;
        sort(infected.begin(), infected.end());
        vector<int> distance;
        for(int i = 0; i < infected.size() - 1; ++i) {
            distance.emplace_back(infected[i + 1] - infected[i]);
        }
        distance.emplace_back(infected[0] - infected.back() + n);
        sort(distance.begin(), distance.end(), [](int a, int b) {return a > b;});
        int sum = 0;
        for(int i = 0; i < distance.size(); ++i) {
            int remainder = distance[i] - 1 - i * 4LL;
            if(remainder > 2) {
                int uninfected = distance[i] - 1 - 1 - i * 4LL;
                sum += uninfected;
            } else if(remainder > 0)
                sum += 1;
        }
        cout << n - sum;

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}