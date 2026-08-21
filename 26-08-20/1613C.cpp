#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check(const vector<int> &attack, const long long &k, const long long &h) {
    long long sum = 0;
    for(int i = 1; i < attack.size(); ++i) {
        sum += attack[i] - attack[i - 1] > k ? k : attack[i] - attack[i - 1]; 
    }
    sum += k;
    if(sum >= h)
        return true;
    else
        return false;
}

int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        long long n = 0, h = 0;
        cin >> n >> h;
        vector<int> attack(n, 0);
        for(auto &x : attack)
            cin >> x;
        long long left = 1, right = h + 1, mid = 0;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(check(attack, mid, h)) {
                right = mid;
            } else 
                left = mid + 1;
        }
        cout << left;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}