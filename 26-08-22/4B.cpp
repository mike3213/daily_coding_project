#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int d = 0, sum_hours = 0;
    cin >> d >> sum_hours;
    vector<pair<int, int>> limits(d, pair<int, int>(0, 0));
    vector<int> ans;
    int min_sum = 0, max_sum = 0;
    for(int i = 0; i < d; ++i) {
        cin >> limits[i].first >> limits[i].second;
        min_sum += limits[i].first;
        max_sum += limits[i].second;
        ans.emplace_back(limits[i].first);
    }
    if(min_sum > sum_hours || max_sum < sum_hours)
        cout << "NO";
    else {
        int remainder = sum_hours - min_sum;
        int cur_sum = min_sum;
        for(int i = 0; i < d; ++i) {
            if(remainder > limits[i].second - limits[i].first) {
                ans[i] = limits[i].second;
                remainder -= (limits[i].second - limits[i].first);
            } else {
                ans[i] += remainder;
                remainder = 0;
                break;
            }
        }
        cout << "YES\n";
        for(int i = 0; i < d; ++i) {
            cout << ans[i];
            if(i != d - 1)
                cout << ' ';
        }
    }
    

    return 0;
}