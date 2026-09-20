#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> vt(n, 0);
        for(auto &x : vt) {
            cin >> x;
        }
        if(n <= 3)
            cout << -1;
        else {
            int cur_max = n, cur_min = 1;
            int left = 0, right = n - 1;
            while(right - left + 1 > 3) {
                bool flag1 = false, flag2 = false;
                if(vt[left] == cur_min) {
                    left++;
                    cur_min++;
                }else if(vt[left] == cur_max) {
                    left++;
                    cur_max--;
                } else
                    flag1 = true;

                if(vt[right] == cur_min) {
                    right--;
                    cur_min++;
                } else if(vt[right] == cur_max) {
                    right--;
                    cur_max--;
                } else
                    flag2 = true;

                if(flag1 && flag2) {
                    cout << left + 1 << ' ' << right + 1;
                    break;
                }
            }
            if(right - left + 1 <= 3)
                cout << -1;
        }

        if(cases != 0)
            cout << '\n';
    }

    return 0;
}


/***
 * bool flag = false;
            int cnt_up = 0, cnt_down = 0;
            int cur_state = 0;
            if(vt[0] < vt[1]) {
                cur_state = 1;
            }
            else {
                cur_state = -1;
            }
            int index[3] ={0};
            for(int i = 2; i < n; ++i) {
                int next_state = 0;
                if(vt[i] < vt[i - 1]) 
                    next_state = -1;
                else 
                    next_state = 1;
                if(next_state != cur_state) {
                    if(cur_state == 1)
                        cnt_up++;
                    else
                        cnt_down++;
                    cur_state = next_state;
                    for(int j = 1; j < 3; ++j)
                        index[j - 1] = index[j];
                    index[2] = i - 1;
                    //cout << "***" << vt[i - 1] << "****\n";
                }
                if(cnt_down >= 1 && cnt_up >= 1 && vt[index[1]] < vt[index[2]]) {
                    int left = index[1] - 1, right = index[2] + 1;
                    if(vt[left] < vt[index[2]] && vt[right] > vt[index[1]]) {
                        cout << left + 1 << ' ' << right + 1;
                        flag = true;
                        break;
                    }
                    cnt_down--;
                }
                else if(cnt_up >= 1 && cnt_down >= 1 && vt[index[2]] < vt[index[1]]) {
                    int left = index[1] - 1, right = index[2] + 1;
                    if(vt[left] > vt[index[2]] && vt[right] < vt[index[1]]) {
                        cout << left + 1 << ' ' << right + 1;
                        flag = true;
                        break;
                    }
                    cnt_up--;
                }
            }
            if(!flag) 
                cout << -1;
 */