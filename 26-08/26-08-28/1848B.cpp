#include <bits/stdc++.h>
using namespace std;

/*bool*/ int check(const vector<int>& bridge, /*int step,*/ int k) {
    int n = bridge.size();
    vector<int> last_pos(k + 1, -1);
    vector<int> max(k + 1, 0), sec(k + 1, 0);
    for(int i = 0; i < n; ++i) {
        int cur_color = bridge[i];
        int cur_gap = i - last_pos[cur_color] - 1;
        last_pos[cur_color] = i;
        if(cur_gap > max[cur_color]) {
            sec[cur_color] = max[cur_color];
            max[cur_color] = cur_gap;
        } else if(cur_gap > sec[cur_color])
            sec[cur_color] = cur_gap;
    }
    for(int color = 1; color <= k; ++color) {
        int cur_gap = n - last_pos[color] - 1;
        if(cur_gap > max[color]) {
            sec[color] = max[color];
            max[color] = cur_gap;
        } else if(cur_gap > sec[color])
            sec[color] = cur_gap;
    }
    int ans = 2e9;
    for(int color = 1; color <= k; ++color) {
        int res = std::max(max[color] / 2, sec[color]);
        if(res < ans)
            ans = res;
    }
    /*
    if(step >= ans)
        return true;
    else
        return false;
    */
   return ans;
}


int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> bridge(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> bridge[i];
        int max_step = 0;
        if(n % 2 == 0)
            max_step = (n - 2) / 2;
        else
            max_step = (n - 1) / 2;
        //binary search
        /*
        int left = 0, right = max_step;

        while(left < right) {
            int mid = left + (right - left) / 2;
            bool flag = check(bridge, mid, k);
            if(flag) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << left;
        */
        cout << check(bridge, k);
        if(cases > 0)
            cout << '\n';
    }

    return 0;
}