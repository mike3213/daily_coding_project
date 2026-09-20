#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int days = 0;
        cin >> days;
        vector<int> activity1(days, 0);
        vector<int> activity2(days, 0);
        vector<int> activity3(days, 0);
        for(auto &x : activity1)
            cin >> x;
        for(auto &x : activity2)
            cin >> x;
        for(auto &x : activity3)
            cin >> x;
        pair<int, int> arr[3][3] = {};
        for(int i = 0; i < 3; ++i) {
            int cur_max1 = 0, cur_max2 = 0, cur_max3 = 0;
            for(int j = 1; j < days; ++j) {
                if(activity1[j] > activity1[cur_max1])
                    cur_max1 = j;
                if(activity2[j] > activity2[cur_max2])
                    cur_max2 = j;
                if(activity3[j] > activity3[cur_max3])
                    cur_max3 = j;
            }
            arr[0][i] = {cur_max1, activity1[cur_max1]};
            arr[1][i] = {cur_max2, activity2[cur_max2]};
            arr[2][i] = {cur_max3, activity3[cur_max3]};
            activity1[cur_max1] = -1;
            activity2[cur_max2] = -1;
            activity3[cur_max3] = -1;
        }
        long long sum_days = 0;
        set<int> s;
        for(int i = 0; i < 3; ++i) {
            long long cur_sum = 0;
            s.clear();
            s.emplace(arr[0][i].first);
            cur_sum += arr[0][i].second;
            for(int j = 0; j < 3; ++j) {
                if(s.find(arr[1][j].first) != s.end())
                    continue;
                else {
                    s.emplace(arr[1][j].first);
                    cur_sum += arr[1][j].second;
                }
                for(int k = 0; k < 3; ++k) {
                    if(s.find(arr[2][k].first) != s.end())
                        continue;
                    else {
                        cur_sum += arr[2][k].second;
                        if(cur_sum > sum_days)
                            sum_days = cur_sum;
                        cur_sum -= arr[2][k].second;
                    }
                }
                cur_sum -= arr[1][j].second;
                s.erase(arr[1][j].first);
            }
            cur_sum -= arr[0][i].second;
            s.erase(arr[0][i].first);
        }
        
        cout << sum_days;

        if(cases != 0)
            cout << '\n';
    }

    return 0;
}