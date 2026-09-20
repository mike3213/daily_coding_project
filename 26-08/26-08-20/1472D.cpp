#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num_odd, num_even;
        for(int i = 0; i < n; ++i) {
            int t = 0;
            cin >> t;
            if(t % 2 == 0)
                num_even.emplace_back(t);
            else 
                num_odd.emplace_back(t);
        }
        sort(num_even.begin(), num_even.end(), greater<int>());
        sort(num_odd.begin(), num_odd.end(), greater<int>());
        long long scores_A = 0, scores_B = 0;
        int i = 0, j = 0;
        bool turn = true;
        while(i < num_even.size() && j < num_odd.size()) {
            if(turn) {
                if(num_even[i] > num_odd[j]) {
                    scores_A += num_even[i];
                    i++;
                } else {
                    j++;
                }
                turn = false;
            } else {
                if(num_odd[j] > num_even[i]) {
                    scores_B += num_odd[j];
                    j++;
                } else {
                    i++;
                }
                turn = true;
            }
        }

        if(i == num_even.size()) {
            while(j < num_odd.size()) {
                if(turn) {
                    turn = false;
                } else {
                    scores_B += num_odd[j];
                    turn = true;
                }
                j++;
            }
        } else if(j == num_odd.size()) {
            while(i < num_even.size()) {
                if(turn) {
                    scores_A += num_even[i];
                    turn = false;
                } else {
                    turn = true;
                }
                i++;
            }
        }
        
        if(scores_A > scores_B)
            cout << "Alice";
        else if(scores_A < scores_B)
            cout << "Bob";
        else
            cout << "Tie";
        
        if(cases > 0)
            cout << '\n';
    }

    return 0;
}